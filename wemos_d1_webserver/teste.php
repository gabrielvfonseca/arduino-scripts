<!DOCTYPE html>
<html lang='en'>
<head>
    <meta charset='UTF-8'>
    <title>Arduino Web Alarm Server</title>
    <link rel="shortcut icon" href="icons/flavicon.svg" type="image/svg">
    <meta name='viewport' content='width=device-width, initial-scale=1.0'>
    <!-- <meta http-equiv='refresh' content='2'/> -->
    <script src='libraries/app.js'></script>
    <?php include "db.php"; ?>
    <style>
        @import url('libraries/fonts.css');

        body {
            background: #09090A;
            text-align: center;
        }

        ::placeholder {
            color: #09090A;
            font-family: 'Inconsolata';
            font-weight: 600;
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
            font-family: 'Inconsolata';
            font-weight: 600;
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

        input:focus {
            outline: none;
        }

        label {
            color: #fff;
            font-family: 'Inconsolata';
            font-size: 16px;
            font-weight: 800;
        }

        div form fieldset div input {
            float: left;
        }

        input[type=number], input[type=text] {
            background-color: #fff;
            color: #09090A;
            font-family: 'Inconsolata';
            font-size: 13px;
            font-weight: 600; 
            padding: 5px 10px 5px 10px;
            margin-bottom: 10px;
            border: 0;  
            border-radius: 2px;
        }

        input[type=button], input[type=reset] {
            background-color: #fff;
            color: #09090A;
            font-family: 'Inconsolata';
            font-size: 13px;
            font-weight: 600; 
            cursor: pointer;
            padding: 12px 20px 12px 20px;
            margin: 10px auto;
            border: 0;
            transition: all 0.5s;
            border-radius: 2px;
            width: auto;
            position: relative;
        }

        input[type=button]:hover, input[type=reset]:hover {
            outline: none;
            background-color: #C3C3C3;
            color: #09090A;
        }

        input[type=reset]  {
            margin-left: 2px;
        }

        #dash_module1, #dash_module2, #dash_module3 {
            margin-right: 10px;
        }

        #container {
            width: 100%;
            height: 100%;
            margin: 0;
            padding: 0;
        }

        .content {
            display: flex;
            margin-left: 40px;
            margin-right: 40px;
        }

        path {
            fill: #09090A;
        }

        #note {
            margin: 0%;
            font-size: 15px;
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
</head>
<body>
    <div>
        <h2>Welcome to the Dashboard! &#128075;</h2>
        <div id="content">
            <div id="dash_module1">
                <from>
                    <fieldset>
                        <legend>LED CONTROLLER</legend>

                        <h4>Turn ON/OFF the LED</h4>

                        <div style="margin-top: 22px; margin-bottom: 30px;">
                            <input type='button' id='buttonLED' value='ON' onclick="sendToArduino('LED', 'ON');">
                            <input type='button' id='buttonLED' value='OFF' onclick="sendToArduino('LED', 'OFF');">
                        </div>

                        <p id="note" style="margin-bottom: 28px;">
                            NOTA: Este controlo <br>do LED é manual!
                        </p>
                        
                        <p>LED Status: <script>document.write(localStorage.getItem("TextStatusLED"));</script></p>

                    </fieldset>
                </from>
            </div>

            <div id="dash_module2">
                <from>
                    <fieldset>
                        <legend>SMOKE SENSOR</legend>

                        <h4>DATA READ BY THE SENSOR</h4>

                        <div>
                            <!-- Graphic of Smoke -->
                            <div id="SmokeGraphic"></div>
                        </div>

                        <script>
                            anychart.onDocumentLoad(function() {
                                // (A) JAVASCRIPT
                                var arrayA = [];

                                arrayA[0] = Number(<?php $sensorMQ2[0] ?>);
                                arrayA[1] = Number(<?php $sensorMQ2[1] ?>);
                                arrayA[2] = Number(<?php $sensorMQ2[2] ?>);
                                arrayA[3] = Number(<?php $sensorMQ2[3] ?>);

                                var rawData = [
                                    ["A", arrayA[0], arrayA[0]],
                                    ["B", arrayA[1], arrayA[1]],
                                    ["C", arrayA[2], arrayA[2]],
                                    ["D", arrayA[3], arrayA[3]]
                                ];

                                console.log("A: " + arrayA[0] + "\nB: " + arrayA[1] + "\nC: " + arrayA[2] + "\nD: " + arrayA[3]);

                                var dataSet = anychart.data.set(rawData);

                                var view = dataSet.mapAs({x: 0, value: 2});

                                // create a chart
                                var chart = anychart.line();
                                // create two line series
                                chart.line(view).name("MQ-2 SENSOR");

                                // set title and draw a chart
                                //chart.title("AnyChart: Combined Chart from the Data Set");
                                chart.legend(true);
                                chart.container("SmokeGraphic").draw();
                            });
                        </script>

                        <p>Smoke Sensor: <script>document.write("ACTIVE");</script></p>

                    </fieldset>
                </from>
            </div>

            <div id="dash_module3">
                <from>
                    <fieldset>
                        <legend>TEMPERATURE SENSOR</legend>

                        <h4>DATA READ BY THE SENSOR</h4>

                        <div>
                            <!-- Graphic of the Temperature -->
                            <div id="TemperatureGraphic"></div>
                        </div>

                        <script>
                            anychart.onDocumentLoad(function() {
                                // (B) JAVASCRIPT
                                var arrayB = [];

                                arrayB[0] = Number(<?php $sensorLM35[0] ?>);
                                arrayB[1] = Number(<?php $sensorLM35[1] ?>);
                                arrayB[2] = Number(<?php $sensorLM35[2] ?>);
                                arrayB[3] = Number(<?php $sensorLM35[3] ?>);

                                var rawData = [
                                    ["A", arrayB[0], arrayB[0]],
                                    ["B", arrayB[1], arrayB[1]],
                                    ["C", arrayB[2], arrayB[2]],
                                    ["D", arrayB[3], arrayB[3]]
                                ];

                                console.log("A: " + arrayB[0] + "\nB: " + arrayB[1] + "\nC: " + arrayB[2] + "\nD: " + arrayB[3]);

                                var dataSet = anychart.data.set(rawData);

                                var view = dataSet.mapAs({x: 0, value: 2});

                                // create a chart
                                var chart = anychart.line();
                                // create two line series
                                chart.line(view).name("LM35 SENSOR");

                                // set title and draw a chart
                                //chart.title("AnyChart: Combined Chart from the Data Set");
                                chart.legend(true);
                                chart.container("TemperatureGraphic").draw();
                            });
                        </script>

                        <p>Temperature Sensor: <script>document.write("ACTIVE");</script></p>

                    </fieldset>
                </from>
            </div>

            <div id="dashboard_arduino">
                <from>
                    <fieldset>
                        <legend>ESP8266 SERVER</legend>

                        <h4>ADJUST SERVER CONFIGS</h4>

                        <form>
                            <div style="text-align: left; margin-top: 10px;">
                                <label for="sensor_sensebility">Sensability:</label>
                                <input type='number' id='sensor_sensebility' placeholder='DEFAULT: 400' onclick="sendToArduino();">
                                <br>
                                <label for="sensor_precisely">Precisely:&nbsp;&nbsp;</label>
                                <input type='number' id='sensor_precisely' placeholder='DEFAULT: 4' onclick="sendToArduino();">
                            </div>
                            <p id="note">
                                NOTA: Quanto maior o número <br>especificado mais lento <br>ficará o sistema!
                            </p>
                            <br>
                            <input type='button' value='UPDATE' onclick="sendToArduino('SENSOR', 'SEND');">
                            <input type='reset' value='RESTART'>
                        </form>
                    </fieldset>
                </from>
            </div>
        </div>
        <br>
        <!-- Program Developed by  -->
        <p>Dev by <a id='dev' href='https://github.com/gabrielfonseca-dev/'>Gabriel</a>.</p>
    </div>

    <script>
        var statusLED;

        function sendToArduino(sensor, status) {
            if (sensor == 'LED') {
                // If the sensor selected is the LED
                if (status == 'ON') {
                    // If the ON button was pressed
                    statusLED = 'ON';
                }

                else if (status == 'OFF') {
                    // If the OFF button was pressed
                    statusLED = 'OFF';
                }
                
                console.log(statusLED);
                localStorage.setItem("TextStatusLED", statusLED); // Set LED status on localstorage
                location.href = ('?ledstatus=' + statusLED);
            }
            else if (sensor == 'LM35') {
                // If the sensor selected is the LM35
            }
            else if (sensor == 'MQ2') {
                // If the sensor selected is the MQ2
            }
            else if (sensor == "SERVER" && sensor == "SEND") {
                var docElement1 = document.getElementById("sensor_precisely").value; // sensor_precisely
                var docElement2 = document.getElementById("sensor_sensebility").value; // sensor_sensebility

                if (docElement1 == "" || docElement2 == "") {
                    // If the value is null, nothing happens
                    alert("You can send nulled values! Fill the empty boxe!");
                }
                else {
                    // Send data to server!
                    alert("Be careful that higher numbers can influence the read latency of the sensors!");
                    console.log("Data have been send to the server!"); 
                }
            }
        }

        function restart() {
            // Restarts Arduino
            var verification = prompt("Are you sure you want to restart? (Y/N)");

            if (verification == "Y") {
                // Restart, send command to arduino
            }
        }
    </script>
</body>
</html>