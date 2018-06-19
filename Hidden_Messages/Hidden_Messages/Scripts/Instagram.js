    "use strict";
    
/*************************************************************

    Following Code is for connection to instagram Api

************************************************************************/
    const client_id = "80a0022e93ff4682a64f5df88609dc7c";
    const client_secret = "49f5498b6a754ab2b7546a9105885b6d";
    const redirectURI = "http://localhost:56352";

    let AccessToken = "";


    function GetAccessToken() {
        let Hashes = location.hash;
        Hashes.split("#").forEach(function (element) {
            if (element.includes("=")) {
                if (element.split("=")[0] == "access_token") {
                    AccessToken = element.split("=")[1];
                    return AccessToken;
                }
            }
        });
    }
    
    function login() {
        if (AccessToken == "") {
            GetAccessToken();
        }
        if (AccessToken == "") {
            window.location.href = "https://api.instagram.com/oauth/authorize/?client_id=" + client_id + "&redirect_uri=" + redirectURI + "&response_type=token&scope=public_content";
        }
    };

    function sendPictureToInstagram(uploadPictureUrl) {
        let pictureID;

        return pictureID;
    };

    function getPicture(pictureID) {

        /* new pictureUrl ??? */
        let message = getIncodedText();
        return message;
    };


    /*$.ajax({
        url: 'https://api.instagram.com/oauth/authorize/',
        beforeSend: function (xhr) {
            xhr.setRequestHeader("client_id", client_id);
            xhr.setRequestHeader("client_secret", client_secret);
            xhr.setRequestHeader("grant_type", "authorization_code");
            xhr.setRequestHeader("redirect_uri", window.location.hostname);
            xhr.setRequestHeader("code", "CODE");
        
        }, success: function (data) {
        
            // Get AccessToken
        
            //alert(data);
            //process the JSON data etc
        }
    });*/

    /*$.ajax({
        url: 'https://api.instagram.com/v1/tags/nofilter/media/recent',
        type: 'GET',
        dataType: 'json',
        contentType: "application/json",
        beforeSend: function (xhr) {
            xhr.setRequestHeader("access_token", AccessToken);
        },
        success: function (data) {
            alert(data);
        }
    });*/


/******************************************************************

    Following Code is a representation of encryption and decryption use

*******************************************************************/
    const password = ""; //Used to further encrypt message into picture

    function DoUpload() {
        const pathBox = document.getElementsByName("ImgPath")[0];
        const textBox = document.getElementsByName("MsgTxt")[0];

        let path = pathBox.value;
        if (path == ""){
            path = "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRKMIMpGBHavLy1F_6p2sFuN8utQzdJ0ozju8mq0FQQejqVJLjpxA";
        }
        let text = textBox.value;

        //Preview
        let img = document.getElementById('Preview');
        img.src = path;

        //Encode
        EncodePicture(path, text, AfterEncoding); //returns Datasource for image as param to AfterEncoding
    }

    function AfterEncoding(dataSource) {
        //View Encoded
        let img = document.getElementById('Encoded');
        img.src = dataSource;

        //send pic to instagram
        //download pic from instagram

        DecodePicture(dataSource, AfterDecoding); //returns DecodedMessage for display as param to AfterDecoding
    }

    function AfterDecoding(Message) {
        let label = document.getElementById('Decoded_Message');
        label.innerHTML = Message;
    }
