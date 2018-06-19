
/************************************************************************ Encoding and decoding functions */
function EncodePicture(pictureUrl, message, CallBack) {
    let img = document.createElement("img");
    img.crossOrigin = 'anonymous';
    img.onload = function () {
        let canvas = document.createElement("canvas");
        let ctx = canvas.getContext('2d');
        ctx.canvas.width = img.width;
        ctx.canvas.height = img.height;
        ctx.drawImage(img, 0, 0);

        // encrypt the message with supplied password if necessary
        if (password.length > 0) {
            message = sjcl.encrypt(password, message);
        } else {
            message = JSON.stringify({ 'text': message });
        }

        // exit early if the message is too big for the image
        var pixelCount = ctx.canvas.width * ctx.canvas.height;
        if ((message.length + 1) * 16 > pixelCount * 4 * 0.75) {
            alert('Message is too big for the image.');
            return;
        }
        if (message.length > maxMessageSize) {
            alert('Message is too big.');
            return;
        }

        // encode the encrypted message with the supplied password
        let imgData = ctx.getImageData(0, 0, ctx.canvas.width, ctx.canvas.height);
        encodeMessage(imgData.data, sjcl.hash.sha256.hash(password), message);
        ctx.putImageData(imgData, 0, 0);

        CallBack(canvas.toDataURL()); //Done
    };
    img.src = pictureUrl;
};

function DecodePicture(pictureUrl, CallBack) {
    let img = document.createElement("img");
    img.crossOrigin = 'anonymous';
    img.onload = function () {
        let canvas = document.createElement("canvas");
        let ctx = canvas.getContext('2d');
        ctx.canvas.width = img.width;
        ctx.canvas.height = img.height;
        ctx.drawImage(img, 0, 0);

        let imgData = ctx.getImageData(0, 0, ctx.canvas.width, ctx.canvas.height);
        let message = decodeMessage(imgData.data, sjcl.hash.sha256.hash(password));

        // try to parse the JSON "as message right now is JSON"
        let obj = null;
        try {
            obj = JSON.parse(message);
        } catch (e) {
            if (password.length > 0) {
                alert("Not right password"); //Failed on password ??
            }
        }

        if (obj) //Message is found
        {
            // decrypt if necessary
            if (obj.ct) {
                try {
                    obj.text = sjcl.decrypt(password, message);
                } catch (e) {
                    alert(passwordFail);
                }
            }

            // escape special characters
            var escChars = {
                '&': '&amp;',
                '<': '&lt;',
                '>': '&gt;',
                '"': '&quot;',
                '\'': '&#39;',
                '/': '&#x2F;',
                '\n': '<br/>'
            };
            const escHtml = function (string) {
                return String(string).replace(/[&<>"'\/\n]/g, function (c) {
                    return escChars[c];
                });
            };
            let DoneMessage = escHtml(obj.text);
            CallBack(DoneMessage); //Done
        }
    };
    img.src = pictureUrl;
};

/******************************************************************
    Following code is for incrypting message into a picture
    The following code is made from this project:
    https://sekao.net/pixeljihad/about.html
*******************************************************************/
const maxMessageSize = 1000;

/************************************************************************** various small functions */
// returns a 1 or 0 for the bit in 'location'
function getBit(number, location) {
    return ((number >> location) & 1);
};

// sets the bit in 'location' to 'bit' (either a 1 or 0)
function setBit(number, location, bit) {
    return (number & ~(1 << location)) | (bit << location);
};

// returns an array of 1s and 0s for a 2-byte number
function getBitsFromNumber(number) {
    let bits = [];
    for (let i = 0; i < 16; i++) {
        bits.push(getBit(number, i));
    }
    return bits;
};

// returns the next 2-byte number
function getNumberFromBits(bytes, history, hash) {
    let number = 0, pos = 0;
    while (pos < 16) {
        let loc = getNextLocation(history, hash, bytes.length);
        let bit = getBit(bytes[loc], 0);
        number = setBit(number, pos, bit);
        pos++;
    }
    return number;
};

// returns an array of 1s and 0s for the string 'message'
function getMessageBits(message) {
    let messageBits = [];
    for (var i = 0; i < message.length; i++) {
        let code = message.charCodeAt(i);
        messageBits = messageBits.concat(getBitsFromNumber(code));
    }
    return messageBits;
};

// gets the next location to store a bit
function getNextLocation(history, hash, total) {
    let pos = history.length;
    let loc = Math.abs(hash[pos % hash.length] * (pos + 1)) % total;
    while (true) {
        if (loc >= total) {
            loc = 0;
        } else if (history.indexOf(loc) >= 0) {
            loc++;
        } else if ((loc + 1) % 4 === 0) {
            loc++;
        } else {
            history.push(loc);
            return loc;
        }
    }
};
/**************************************************************************/

// encodes the supplied 'message' into the CanvasPixelArray 'colors'
function encodeMessage(colors, hash, message) {
    // make an array of bits from the message
    let messageBits = getBitsFromNumber(message.length);
    messageBits = messageBits.concat(getMessageBits(message));

    // this will store the color values we've already modified
    let history = [];

    // encode the bits into the pixels
    let pos = 0;
    while (pos < messageBits.length) {
        // set the next color value to the next bit
        let loc = getNextLocation(history, hash, colors.length);
        colors[loc] = setBit(colors[loc], 0, messageBits[pos]);

        // set the alpha value in this pixel to 255
        // we have to do this because browsers do premultiplied alpha
        // see for example: http://stackoverflow.com/q/4309364
        while ((loc + 1) % 4 !== 0) {
            loc++;
        }
        colors[loc] = 255;

        pos++;
    }
};

// returns the message encoded in the CanvasPixelArray 'colors'
function decodeMessage(colors, hash) {
    // this will store the color values we've already read from
    var history = [];

    // get the message size
    var messageSize = getNumberFromBits(colors, history, hash);

    // exit early if the message is too big for the image
    if ((messageSize + 1) * 16 > colors.length * 0.75) {
        return '';
    }

    // exit early if the message is above an artificial limit
    if (messageSize === 0 || messageSize > maxMessageSize) {
        return '';
    }

    // put each character into an array
    var message = [];
    for (var i = 0; i < messageSize; i++) {
        var code = getNumberFromBits(colors, history, hash);
        message.push(String.fromCharCode(code));
    }

    // the characters should parse into valid JSON
    return message.join('');
};