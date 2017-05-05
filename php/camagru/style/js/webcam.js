var canvas = document.getElementById('canvas'),
    context = canvas.getContext('2d'),
    kitten = document.getElementById('kitten'),
    video = document.querySelector('video'),
    capture = document.getElementById('capture'),
    tf = document.getElementById('tf'),
    atom = document.getElementById('atom'),
    fh = document.getElementById('fh'),
    will = document.getElementById('will'),
    option = document.getElementById('option'),
    webcam = document.getElementById('webcam'),
    nocam = document.getElementById('nocam'),
    side = document.getElementById('side');

var camera = false;

// Older browsers might not implement mediaDevices at all, so we set an empty object first
if (navigator.mediaDevices === undefined) {
  navigator.mediaDevices = {};
}

// Some browsers partially implement mediaDevices. We can't just assign an object
// with getUserMedia as it would overwrite existing properties.
// Here, we will just add the getUserMedia property if it's missing.
if (navigator.mediaDevices.getUserMedia === undefined) {
  navigator.mediaDevices.getUserMedia = function(constraints) {

    // First get ahold of the legacy getUserMedia, if present
    var getUserMedia = navigator.webkitGetUserMedia || navigator.mozGetUserMedia;

    // Some browsers just don't implement it - return a rejected promise with an error
    // to keep a consistent interface
    if (!getUserMedia) {
      return Promise.reject(new Error('getUserMedia is not implemented in this browser'));
    }

    // Otherwise, wrap the call to the old navigator.getUserMedia with a Promise
    return new Promise(function(resolve, reject) {
      getUserMedia.call(navigator, constraints, resolve, reject);
    });
  }
}

navigator.mediaDevices.getUserMedia({ audio: false, video: true })
.then(webcamStream)
.catch(function(err) {
  console.log(err.name + ": " + err.message);
});

function webcamStream(stream) {
  // Older browsers may not have srcObject
  if ("srcObject" in video) {
    video.srcObject = stream;
  } else {
    // Avoid using this in new browsers, as it is going away.
    video.src = window.URL.createObjectURL(stream);
  }
  video.onloadedmetadata = function(e) {
    video.play();
    camera = true;
    nocam.style.display = "none";
  };

  capture.addEventListener('click', function(e) {
    context.drawImage(video, 0, 0, 400, 300);
    if (img === "tf") {
      context.drawImage(tf, 0, 0, 100, 100);
    } else if (img === "atom") {
      context.drawImage(atom, 0, 0, 100, 100);
    } else if (img === "fh") {
      context.drawImage(fh, 0, 0, 100, 100);
    } else if (img === "will") {
      context.drawImage(will, 0, 0, 100, 100);
    }
    kitten.setAttribute('src', canvas.toDataURL('image/png'));
  });
}

function checkIn(checkbox) {
  if (camera) {
    if (checkbox.id === "tfimg") {
      tf.style.display = "block";
      atom.style.display = "none";
      fh.style.display = "none";
      will.style.display = "none";
      img = "tf";
    } else if (checkbox.id === "atomimg") {
      tf.style.display = "none";
      atom.style.display = "block";
      fh.style.display = "none";
      will.style.display = "none";
      img = "atom";
    } else if (checkbox.id === "fhimg") {
      tf.style.display = "none";
      atom.style.display = "none";
      fh.style.display = "block";
      will.style.display = "none";
      img = "fh";
    } else if (checkbox.id === "willimg") {
      tf.style.display = "none";
      atom.style.display = "none";
      fh.style.display = "none";
      will.style.display = "block";
      img = "will";
    } else {
      tf.style.display = "none";
      atom.style.display = "none";
      fh.style.display = "none";
      will.style.display = "none";
    }
    capture.style.display = "block";
  } else {
    // pas de cam
    capture.style.display = "none";
    nocam.style.display = "block";
  }
}
