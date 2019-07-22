'use strict';

exports.handler = (event, context, callback) => {
    const request = event.Records[0].cf.request;

    if (request.uri !== '/some_data_file.dat') {
        // for the demo we only want to deal with requests for this file
        callback(null, request);
        return;
    }

    const pathNewData = '/NewFormat';
    const pathOldData = '/OldFormat';

    let revisedUri;
    
    const querystring = require('querystring');
    var queryObj = querystring.parse(request.querystring)
    if('version' in queryObj) {
        if(parseFloat(queryObj.version) > 10.1) {
            revisedUri = pathOldData + request.uri;
        }
        else {
            revisedUri = pathOldData + request.uri;
        }
    }
    else {
        // assume old format before we started passing in the version
        revisedUri = pathOldData + request.uri;
    }

    request.uri = revisedUri;
    console.log(`Request uri set to "${request.uri}"`);
    callback(null, request);
};
