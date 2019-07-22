#include <iostream>

#include <aws/core/Aws.h>
#include <aws/core/utils/logging/ConsoleLogSystem.h>
#include <aws/core/utils/logging/AWSLogging.h>
#include <aws/core/utils/Outcome.h>

#include <aws/core/http/HttpRequest.h>
#include <aws/core/http/HttpResponse.h>
#include <aws/core/http/HttpClientFactory.h>
#include <aws/core/http/HttpClient.h>
#include <aws/core/client/ClientConfiguration.h>

#include "settings.h"

using namespace std;

int main()
{
    Aws::SDKOptions options;

    Aws::Utils::Logging::LogLevel logLevel{ Aws::Utils::Logging::LogLevel::Error };
    options.loggingOptions.logger_create_fn = [logLevel] {return make_shared<Aws::Utils::Logging::ConsoleLogSystem>(logLevel); };

    Aws::InitAPI(options);

    cout << "Type in your version: ";
    int version;
    if (!(cin >> version))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    stringstream url;
    url << CLOUDFRONT_URL << "?version=" << version;

    auto request = Aws::Http::CreateHttpRequest(url.str(),
        Aws::Http::HttpMethod::HTTP_GET,
        Aws::Utils::Stream::DefaultResponseStreamFactoryMethod);
    auto httpClient = Aws::Http::CreateHttpClient(Aws::Client::ClientConfiguration());
    auto response = httpClient->MakeRequest(request);
    if (response->GetResponseCode() == Aws::Http::HttpResponseCode::OK)
    {
        stringstream responseBody;
        responseBody << response->GetResponseBody().rdbuf();
        cout << "File retrieved: " << endl << responseBody.str() << endl << endl;
    }
    else
    {
        cout << "Unable to get file. HTTP status returned: " << static_cast<int>(response->GetResponseCode()) << endl << endl;
    }

    Aws::ShutdownAPI(options);
    return 0;
}

