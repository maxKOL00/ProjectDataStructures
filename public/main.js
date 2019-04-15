
function fetchStartEndpoint(fileName) {
  fetch(`/start/${fileName}`)//gets the name of the python script from the function the button calls
    .catch(error => console.log(error));
}

document.getElementById("meme").style.display = 'none';//begin with button hidden
function writeMemes() {
  var x = document.getElementById("meme");
  if (x.style.display === 'none') {
        x.style.display = 'inline';//toggle display of the button that runs the script
  } else {
    x.style.display = 'none';
    document.getElementById("meme").checked = false;
  }
}

document.getElementById("check1").style.display = 'none';
function check1() {
  var x = document.getElementById("check1");
  if (x.style.display === 'none') {
        x.style.display = 'inline';
  } else {
    x.style.display = 'none';
    document.getElementById("check1").checked = false;
  }

  fetchStartEndpoint("reddit.py") //give the name of the python script to server.js
}