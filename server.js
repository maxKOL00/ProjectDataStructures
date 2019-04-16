let PythonShell = require('python-shell');//node package
var options = {
  mode: 'text',
  pythonPath: 'C:\\Users\\Max\\AppData\\Local\\Programs\\Python\\Python37-32\\Scripts\\',//environment variable
  pythonOptions: ['-u'],
  scriptPath: 'C:\\Users\\Max\\OneDrive\\ds-project',//location of reddit.py

}
express = require('express'); //web server
app = express();

app.listen(8080, function () { //start the webserver on port 8080
  console.log("server running on port http://localhost:8080");
})

app.use(express.static('public')); //tell the server that ./public/ contains the static webpages



app.get('/start/:fileName', function(req, res) {  //get the name of the script
  let fileName = req.params.fileName;
  console.log(fileName)
  PythonShell.run(`./public/${fileName}`, function (err,results) {//say where the script is
    console.log('results: %j',results);//log the output of the python script
    if (err) throw err;
    console.log('finished');//when the script has finnished running
  });
});

