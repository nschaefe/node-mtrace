
# node-mtrace
NPM module wrapping the native [mtrace](https://www.gnu.org/software/gnulib/manual/html_node/mtrace.html) functions.

# Prerequisites
The implementation uses the [Node-API](https://nodejs.org/api/n-api.html#node-api).
node-mtrace requires at least the Node-API version 1 delivered with node v8.4.0. However, for node versions < 10 the Node-API was experimental and evolving. We recommend node versions >=10. For compatibility with your node version check the used Node-API functions and the [Node-API version matrix](https://nodejs.org/api/n-api.html#node-api-version-matrix).

# Build
Compile the node module with

    node-gyp configure build  

 Package the module with 

    npm pack

# Usage
For examples checkout the **examples** folder.
