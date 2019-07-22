## Amazon Cloudfront Versioned File Retrieval Using AWS Cpp SDK

A small sample that shows how to use the AWS C++ SDK to retrieve a file using HTTP requests.

## Requirements
- An AWS account with access to Amazon Cognito: https://aws.amazon.com/getting-started/
- Microsoft Visual Studio 2017 or higher (any edition): https://visualstudio.microsoft.com/

## Contents
├── AWS/                     # Source for an AWS Lambda function to choose an asset

├── FilesToUploadToAmazonS3/ # Sample files to demonstrate assets with different versions

└── GameClient/              # Contains solution file as well the sample source code

    ├── GameClient.sln       # Solution that builds the sample
    
    ├── GameClient.cpp       # The C++ code showing how to use the HTTP library
    
    └── settings.h           # Configuration header to choose the URL to GET from
    

## Building and using the sample
This code accompanies an article on downloading versioned game assets from Cloudfront, however it also shows how to use the AWS C++ SDK HTTP library to perform GET operations.  You can find the article here: https://aws.amazon.com/blogs/gametech/how-to-deliver-custom-game-content-to-players-using-lambdaedge

## License Summary

This sample code is made available under the MIT-0 license. See the LICENSE file.
