const http = require("http");
var mtrace = require("mtrace");

const hostname = "127.0.0.1";
const port = 3000;

/**
 * This is an example using the wrapped mtrace functions.
 *
 * PREREQUISITES:
 * - compile the node module first (see main README)
 * - install the node module by running "npm install pathToModule" in this directory
 * - set the env variable MALLOC_TRACE, the target log file
 *   like MALLOC_TRACE=~/mtrace.out
 * 
 * RUN: node test_mtrace.js
 * Access the server via browser.
 * After running the program there should be content in the specified log file.
 */
const server = http.createServer((req, res) => {
  console.log(`Environment variable MALLOC_TRACE has value: ${process.env["MALLOC_TRACE"]}`);
  mtrace.mtrace();
  allocate();
  mtrace.muntrace();

  res.statusCode = 200;
  res.setHeader("Content-Type", "text/plain");
  res.end("Done. mtrace results should be present.");
});

function allocate() {
  for (var i = 0; i < 10; i++) {
    const url = new URL("http://example." + i);
    console.log(`${url.href}`);
  }
}

server.listen(port, hostname, () => {
  console.log(`Server running at http://${hostname}:${port}/`);
});
