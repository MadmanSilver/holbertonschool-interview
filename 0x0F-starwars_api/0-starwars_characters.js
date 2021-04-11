#!/usr/bin/node

const request = require('request');

const asyncChars = async function (url) {
  return new Promise(function (resolve, reject) {
    request(url, function (err, res, body) {
      if (err) {
        reject(err);
      }
      resolve(JSON.parse(body).name);
    });
  });
};

request('https://swapi-api.hbtn.io/api/films/' + process.argv[2], function (err, res, body) {
  if (err) {
    return console.log(err);
  }
  JSON.parse(body).characters.forEach(character => {
    (async function () {
      const res = await asyncChars(character);
      console.log(res);
    })();
  });
});
