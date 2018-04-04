//---------//
/* Modules */
//---------//
const https = require('https');
const {exec} = require('child_process');

//---------//
/* Globals */
//---------//
//fetchData stuff
const fetchOptions = {
    host: 'student-diss.data.thethingsnetwork.org',
    path: '/api/v2/query/demo',
    headers: {
        accept: 'application/json',
        authorization: 'key ttn-account-v2.Cx4Re2sKJ897BRDBoTTcWlUFfN4deKyGHmgXIQtmPzI'
    }
};
const fetchInterval = (10 * 1000);  //10secs
var data;
//printData stuff
const printInterval = (11 * 1000);   //11secs

//-------------//
/* Entry Point */
//-------------//
setInterval(fetchData, fetchInterval);
setInterval(printData, printInterval);

//-----------//
/* Functions */
//-----------//
function fetchData() {
    console.log('fetching data... ' + fetchOptions.host + fetchOptions.path);

    https.get(fetchOptions, (response) => {
        let responseData = '';

        response.on('data', (chunk) => {
            responseData += chunk;
        });

        response.on('end', () => {
            data = JSON.parse(responseData).map((element, index) => {
                return [element.time, element.raw];
            });
        });
    }).on('error', (err) => {
        console.error('ERR! fetchData()');
        console.error(err);
    });
};

function printData() {
    for (let i = 0; i < data.length; i++) {
        exec('echo '+data[i][1]+' | base64 --decode', (err, stdout, stderr) => {
            if (err)
                console.error(err);
            else
                console.log('['+data[i][0]+'] '+stdout.toString('ascii'));
        });
    }
};

