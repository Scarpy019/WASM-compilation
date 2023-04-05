

// Assume add.wasm file exists that contains a single function adding 2 provided arguments
const fs = require('fs');

const wasmBuffer = fs.readFileSync('./test_no_link.wasm');
WebAssembly.instantiate(wasmBuffer).then(wasmModule => {
  console.log(wasmModule.instance.exports);
  console.log(wasmModule.instance.exports.adder(15));
});