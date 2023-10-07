<!DOCTYPE html>
<html lang='en'>
<head>
    <meta charset='UTF-8'>
    <title>Arduino Web Alarm</title>
    <link rel="shortcut icon" href="icons/flavicon.svg" type="image/svg">
    <meta name='viewport' content='width=device-width, initial-scale=1.0'>
    <script src='libraries/app.js'></script>
    <?php include "db.php"; ?>
    <style>
        @import url('libraries/fonts.css');

        body {
            background: #09090A;
            text-align: center;
        }

        div {
            display: inline-block;
            margin-left: auto;
            margin-right: auto;
        }

        div p {
            text-align: center;
        }

        p, span {
            align-items: center;
            color: #fff;
            font-size: 14px;
            font-family: 'Inconsolata';
            font-weight: 600;
            line-height: 1;
        }

        a {
            text-decoration: none !important;
        }

        h2 {
            text-align: center;
            font-family: "Inconsolata";
            font-size: 18px;
            color: #fff;
            font-weight: bold; 
        }

        h4 {
            text-align: left;
            font-family: 'Inconsolata';
            font-size: 14px;
            color: #fff;
            font-weight: bold;
            margin-top: 15px;
            margin-bottom: 10px;
            margin-right: 5px;
            margin-left: 5px;
            text-align: center;
        }

        fieldset {
            margin-top: 20px;
            margin-right: 10px;
        }

        fieldset fieldset {
            align-items: center;
            text-align: center;
        }

        legend {
            border: 2px solid #fff; 
            font-size: 15px; 
            font-weight: bold; 
            color: #fff; 
            font-family: 'Inconsolata';
            padding: 5px;
        }

        input:focus, button:focus {
            outline: none;
        }

        label {
            color: #fff;
            font-family: 'Inconsolata';
            font-size: 16px;
            font-weight: 800;
        }

        input[type=text], input[type=password] {
            background-color: transparent;
            width: 10rem;
            height: 1rem;
            border: 1px solid #fff;
            align-items: center;
            color: #fff;
            font-family: "Inconsolata";
            font-weight: 600;
            font-size: 14px;
            padding: 6px;
            margin-bottom: 14px;
        }

        input[type=button], #loginBtn {
            background-color: #fff;
            color: #09090A;
            font-family: 'Inconsolata';
            font-size: 13px;
            font-weight: 600; 
            cursor: pointer;
            padding: 12px 20px 12px 20px;
            margin: 10px auto;
            border: solid;
            transition: all 0.5s;
            border-radius: 5px;
            width: 6rem;
            position: relative;
        }

        input[type=button]:hover, #loginBtn:hover {
            outline: none;
            background-color: #C3C3C3;
            color: #09090A;
        }

        button {
            background-color: transparent;
            color: #09090A;
            font-family: 'Inconsolata';
            font-size: 13px;
            font-weight: 600; 
            padding: 30px;
            margin: 10px auto;
            border-color: #c5c5c5;
            transition: all 0.5s;
            border-radius: 40px;
            width: auto;
            margin-right: 16px;
            margin-left: 16px;
            margin-top: 39px;
            margin-bottom: 39px;
            position: relative;
        }

        #dash {
            display: none;
            align-items: center;
            text-align: center;
        }

        #dash_module1, #dash_module2, #dash_module3, #dash_module4, #dash_module5 {
            margin-right: 10px;
        }

        #container {
            width: 100%;
            height: 100%;
            margin: 0;
            padding: 0;
        }

        path {
            fill: #09090A;
        }

        #errorMessage {
            color: #FF0000;
        }

        .anychart-credits-logo, .anychart-credits-text {
            display: none;
        }

        #dev {
            color: #fff;
        }

        #dev:hover {
            color: #0099FF;
        }
    </style>
    <script>
        function objects(a, b, c, d, e, f, g, h, i, j) {
            this.a = a;
            this.b = b;
            this.c = c;
            this.d = d;
            this.e = e;
            this.f = f;
            this.g = g;
            this.h = h;
            this.i = i;
            this.j = j;
        }
    </script>
</head>
<body>
    <div>
        <!-- Authentication form -->
        <div id="auth">
            <form>
                <fieldset>
                    <div style="padding: 15px; align-items: center;">
                        <img src="icons/flavicon.svg" alt="Logo" width="60" height="60"/>
                        <h2>Login</h2>
                        <p>Please authenticate this <br>form to get access.</p>
                        <p><span id="errorMessage"></span></p>
                        <div>
                            <input type="text" id="user" placeholder="Username"><br>
                            <input type="password" id="pwd" placeholder="Password"><br>
                            <input type="button" id="loginBtn" value="Login">
                        </div>
                    </div>
                </fieldset>
            </form>
        </div>

        <!-- Dashboard form -->
        <div id="dash">
            <h2>Welcome to the Dashboard! &#128075;</h2>
            <div id="dash_module1">
                <from>
                    <fieldset>
                        <h4>Smoke Sensor</h4>

                        <div>
                            <!-- Graphic of Smoke -->
                            <div id="SmokeGraphic"></div>
                        </div>

                        <script>
                            function smokeSensor() {
                                // Smoke
                                var arrayA = [];
                                arrayA[0] = Number(<?php echo $sensorMQ2[9] ?>);
                                arrayA[1] = Number(<?php echo $sensorMQ2[8] ?>);
                                arrayA[2] = Number(<?php echo $sensorMQ2[7] ?>);
                                arrayA[3] = Number(<?php echo $sensorMQ2[6] ?>);
                                arrayA[4] = Number(<?php echo $sensorMQ2[5] ?>);
                                arrayA[5] = Number(<?php echo $sensorMQ2[4] ?>);
                                arrayA[6] = Number(<?php echo $sensorMQ2[3] ?>);
                                arrayA[7] = Number(<?php echo $sensorMQ2[2] ?>);
                                arrayA[8] = Number(<?php echo $sensorMQ2[1] ?>);
                                arrayA[9] = Number(<?php echo $sensorMQ2[0] ?>);

                                var rawData = [
                                    ["A", arrayA[0], arrayA[0]],
                                    ["B", arrayA[1], arrayA[1]],
                                    ["C", arrayA[2], arrayA[2]],
                                    ["D", arrayA[3], arrayA[3]],
                                    ["E", arrayA[4], arrayA[4]],
                                    ["F", arrayA[5], arrayA[5]],
                                    ["G", arrayA[6], arrayA[6]],
                                    ["H", arrayA[7], arrayA[7]],
                                    ["I", arrayA[8], arrayA[8]],
                                    ["J", arrayA[9], arrayA[9]]
                                ];

                                var table = {};

                                table.MQ2 = new objects(
                                    arrayA[0], arrayA[1], arrayA[2], arrayA[3], 
                                    arrayA[4], arrayA[5], arrayA[6], arrayA[7], 
                                    arrayA[8], arrayA[9]
                                );

                                console.table(table);

                                var dataSet = anychart.data.set(rawData);

                                var view = dataSet.mapAs({x: 0, value: 2});

                                // create a chart
                                var chart = anychart.line();
                                // create two line series
                                chart.line(view).name("MQ-2 SENSOR");
                                // Set legend
                                chart.legend(true);
                                chart.container("SmokeGraphic").draw();
                            }
                            anychart.onDocumentLoad(function() {smokeSensor();});
                        </script>
                    </fieldset>
                </from>
            </div>

            <br>

            <div id="dash_module2">
                <from>
                    <fieldset>
                        <h4>Temperature Sensor</h4>

                        <div>
                            <!-- Graphic of the Temperature -->
                            <div id="TemperatureGraphic"></div>
                        </div>

                        <script>
                            function temperatureSensor() {
                                // Temperature
                                var arrayB = [];
                                arrayB[0] = Number(<?php echo $sensorLM35[9] ?>);
                                arrayB[1] = Number(<?php echo $sensorLM35[8] ?>);
                                arrayB[2] = Number(<?php echo $sensorLM35[7] ?>);
                                arrayB[3] = Number(<?php echo $sensorLM35[6] ?>);
                                arrayB[4] = Number(<?php echo $sensorLM35[5] ?>);
                                arrayB[5] = Number(<?php echo $sensorLM35[4] ?>);
                                arrayB[6] = Number(<?php echo $sensorLM35[3] ?>);
                                arrayB[7] = Number(<?php echo $sensorLM35[2] ?>); 
                                arrayB[8] = Number(<?php echo $sensorLM35[1] ?>);
                                arrayB[9] = Number(<?php echo $sensorLM35[0] ?>);

                                var rawData = [
                                    ["A", arrayB[0], arrayB[0]],
                                    ["B", arrayB[1], arrayB[1]],
                                    ["C", arrayB[2], arrayB[2]],
                                    ["D", arrayB[3], arrayB[3]],
                                    ["E", arrayB[4], arrayB[4]],
                                    ["F", arrayB[5], arrayB[5]],
                                    ["G", arrayB[6], arrayB[6]],
                                    ["H", arrayB[7], arrayB[7]],
                                    ["I", arrayB[8], arrayB[8]],
                                    ["J", arrayB[9], arrayB[9]]
                                ];

                                var table = {};

                                table.LM35 = new objects(
                                    arrayB[0], arrayB[1], arrayB[2], arrayB[3], 
                                    arrayB[4], arrayB[5], arrayB[6], arrayB[7], 
                                    arrayB[8], arrayB[9]
                                );

                                console.table(table);

                                var dataSet = anychart.data.set(rawData);

                                var view = dataSet.mapAs({x: 0, value: 2});

                                // create a chart
                                var chart = anychart.line();
                                // create two line series
                                chart.line(view).name("LM35 SENSOR");
                                // Set legend
                                chart.legend(true);
                                chart.container("TemperatureGraphic").draw();
                            }
                            anychart.onDocumentLoad(function() {temperatureSensor();});
                        </script>
                    </fieldset>
                </from>
            </div>

            <div id="dash_module4">
                <from>
                    <fieldset>
                        <h4>Server Status</h4>
                        <div>
                            <button id="status" disabled>
                                <span id="statusTxt">OFF</span>
                            </button>
                        </div>
                    </fieldset>
                </form>
            </div>

        </div>
        <br>
        <!-- Program Developed by  -->
        <p>Dev by <a id='dev' href='https://github.com/gabrielfonseca-dev/'>Gabriel</a>.</p>
    </div>

    <script>
        const errorMessage = document.getElementById("errorMessage");
        const auth = document.getElementById("auth");
        const dash = document.getElementById("dash");

        // Get server online status
        var server = Number(<?php echo $serverStatus ?>);
        console.log("Server status: " + server);

        document.getElementById("loginBtn").addEventListener("click", function() {
            var user = document.getElementById("user").value;
            var pwd = document.getElementById("pwd").value;

            if (user == "arduino" && pwd == "arduino") {
                auth.style.display = "none";
                dash.style.display = "inline";
                // Save on localstorage
                localStorage.setItem("auth", "arduino");
            }
            else {
                console.log("Auth failed!");
                if (pwd == "" || user == "") {
                    errorMessage.innerHTML = "Fill all blank spots!";
                }
                else {
                    errorMessage.innerHTML = "Passord is incorrect!";
                }
            }
        });

        if (localStorage.getItem("auth") == undefined) {
            console.log("Login: False");
        }  
        else {
            console.log("Login: True");
            auth.style.display = "none";
            dash.style.display = "inline";

            // Update content every 6 seconds
            setInterval(function(){ 
                location.reload();
            }, 6000);
        } 

        if (server == "ON") {
            document.getElementById("statusTxt").innerHTML = "ON";
            document.getElementById("status").style.borderColor = "#0099FF";
            document.getElementById("statusTxt").style.color = "#0099FF";        
        }
        else {
            document.getElementById("statusTxt").innerHTML = "OFF";
            document.getElementById("status").style.borderColor = "#C5C5C5";
            document.getElementById("statusTxt").style.color = "#C5C5C5";
        }

    </script>
</body>
</html>