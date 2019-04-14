let PythonShell = require('python-shell');
express = require('express'); //web server
app = express();

app.listen(8080, function () { //start the webserver on port 8080
  console.log("server running on port http://localhost:8080");
})

app.use(express.static('./public/')); //tell the server that ./public/ contains the static webpages

// app.get('/', function (req, res) {
//   res.send('hello world');
// });

app.get('/start/:fileName', function(req, res) {  
  let fileName = req.params.fileName;
  console.log(fileName)
  PythonShell.run(`./${fileName}`, function (err,results) {
    console.log('results ',results);
    if (err) throw err;
    console.log('finished');
  });
});

// This was for retrieving a lesson plan, but you found another way. You prob dont need this.
// app.get('/start/:fileName', function(req, res) {
//   let fileName = req.params.fileName;
//   (`/lesson_plans/${fileName}`, function (err) {
//     if (err) throw err;
//     console.log('finished');
//   });
// });
