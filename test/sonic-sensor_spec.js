const chai = require('chai');
const ffi = require('ffi'); // or use node-addon-api for C++

const { expect } = chai;
const myLibrary = ffi.Library('./sonic-sensor', {
    'main': ['int']
}); // Adjust function name and types accordingly

describe('Testing my C/C++ library', function() {
    it('should return the correct result', function() {
        const result = myLibrary.main(); // Adjust arguments
        expect(result).to.equal(0); // Adjust expected result
    });
});