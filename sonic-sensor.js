const ffi = require('ffi');

// Load the shared library
const myLibrary = ffi.Library('./src/sonic-sensor', {
    'main': ['int']
});

// Call a function from your C library
const result = myLibrary.main();
