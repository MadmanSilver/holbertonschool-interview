#!/usr/bin/node

const request = require('request');

const asyncChars = async function (url) {
  return new Promise(function (resolve, reject) {
    request(url, function (err, res, body) {
      if (err) {
        reject(err);
      } else if (res.statusCode === 200) {
        resolve(JSON.parse(body).name);
      } else {
        reject(err);
      }
    });
  });
};

request('https://swapi-api.hbtn.io/api/films/' + process.argv[2], function (err, res, body) {
  if (err) {
    return console.log(err);
  }
  const chars = JSON.parse(body).characters;
  (async function () {
    for (let i = 0; i < chars.length; i++) {
      const res = await asyncChars(chars[i]);
      console.log(res);
    }
  })();
});
