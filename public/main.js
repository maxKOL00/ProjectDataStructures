
//$('.grade-wrapper').on("click", function(e){
  //e.preventDefault()
  //$(this).find("div").slideToggle("slow", function () {
  //});
//})

// const button1 = document.querySelector("#script1");
// const button2 = document.querySelector("#script2");
// const button3 = document.querySelector("#script3");
// const button4 = document.querySelector("#script4");

// button1.addEventListener("click", () => fetchStartEndpoint(button1.dataset.filename));
// button2.addEventListener("click", () => fetchStartEndpoint(button2.dataset.filename));
// button3.addEventListener("click", () => fetchStartEndpoint(button3.dataset.filename));
// button4.addEventListener("click", () => fetchStartEndpoint(button4.dataset.filename));


function fetchStartEndpoint(fileName) {
  fetch(`/start/${fileName}`)
    .catch(error => console.log(error));
}

document.getElementById("meme").style.display = 'none';
function writeMemes() {
  var x = document.getElementById("meme");
  if (x.style.display === 'none') {
        x.style.display = 'inline';
  } else {
    x.style.display = 'none';
    document.getElementById("meme").checked = false;
  }
  // Uncomment below and change snow to the correct file name you want to trigger in python_scripts
  // Do the same for all the others below. 
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
   // Uncomment below and change snow to the correct file name you want to trigger in python_scripts
   // Do the same for all the others below. 
  fetchStartEndpoint("reddit.py") 
}
 

