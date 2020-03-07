// Copyright (c) 2018 ml5
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

/* ===
ml5 Example
Webcam Image Classification using MobileNet and p5.js
This example uses a callback pattern to create the classifier
=== */

let classifier;
let video;
let resultsP;

var serial;
var options_ard = {
    baudRate: 9600
};
var portName = '/dev/cu.usbmodem14601';
var inData;
var outByte = 0;
var code;
var modelrdy = false;

var guessrslts;


function setup() {
    createCanvas(1, 1);
    // Create a camera input
    video = createCapture(VIDEO);
    video.size(500, 500);
    // Initialize the Image Classifier method with MobileNet and the video as the second argument
    classifier = ml5.imageClassifier('MobileNet', video, modelReady);
    resultsP = createP('Loading model and video...');

    serial = new p5.SerialPort();
    serial.on('data', serialEvent);
    serial.on('error', serialEvent);
    serial.open(portName, options_ard);
}

//COREY HELLP --------------------------------------------------/

function draw() {
    document.onkeydown = function (e) {
        if (e.which == 68) {
            outByte = "code"
            serial.write(outByte, function (err) {});
            serial.write('\n', function (err) {
                console.log('errors' + err);
            });


        } else
        if (e.which == 70) {
            outByte = "code2"
            serial.write(outByte, function (err) {});
            serial.write('\n', function (err) {
                console.log('errors' + err);
            });
        } else
        if (e.which == 71) {
            outByte = "code3"
        }
    }

}

//END OF COREY HELLP --------------------------------------------------/

function modelReady() {
    console.log('Model Ready');
    classifyVideo();
    modelrdy = true;
}

// Get a prediction for the current video frame
function classifyVideo() {
    classifier.classify(gotResult);
}

// When we get a result
function gotResult(err, results) {
    // The results are in an array ordered by confidence.
    //    resultsP.html(results[0].label + ' ' + nf(results[0].confidence, 0, 8));
    classifyVideo();

    resultsP.html(results[0].label);

    guessrslts = results[0].label;

}

function scan() {

    console.log(guessrslts);
    outByte = "code"
    serial.write(outByte, function (err) {});
    serial.write('\n', function (err) {
        console.log('errors' + err);
    });

}

function serialEvent() {
    var inString = serial.readStringUntil('/r/n');

    if (inString.length > 0) {
        console.log("nothing");
    }
}
