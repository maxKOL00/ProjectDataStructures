let PythonShell = require('python-shell');
var options = {
  mode: 'text',
  pythonPath: 'C:\\Users\\Max\\AppData\\Local\\Programs\\Python\\Python37-32\\Scripts\\',
  pythonOptions: ['-u'],
  scriptPath: 'C:\\Users\\Max\\OneDrive\\ds-project',

}
express = require('express'); //web server
app = express();

app.listen(8080, function () { //start the webserver on port 8080
  console.log("server running on port http://localhost:8080");
})

app.use(express.static('public')); //tell the server that ./public/ contains the static webpages

// app.get('/', function (req, res) {
//   res.send('hello world');
// });

app.get('/start/:fileName', function(req, res) {  
  let fileName = req.params.fileName;
  console.log(fileName)
  PythonShell.run(`./${fileName}`, function (err,results) {//say where the script is
    console.log('results: %j',results);
    if (err) throw err;
    console.log('finished');
  });
});

