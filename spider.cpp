#include <stdio.h>
#include <curl/curl.h>
#include <libc.h>
#include <iostream>
#include <string>

void exitError(char *str){
    write(2, str, strlen(str));
    exit(1);
}

int parseFlag(char *flag){
    int f = 0;
    if (flag[0] != '-') return 1;
    while (flag[++f]){
        if (flag[f] != 'r' || flag[f] != 'l' || flag[f] != 'p') return 1;
        if (f > 3) return 1;
    }
    return 0;
}

// Callback function to handle the response
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main() {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;
    int counter = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        // Set the URL
        std::string url;
        std::cout << "Enter the URL: ";
        std::cin >> url;

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        
        // Set the write callback function
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        // Perform the request
        res = curl_easy_perform(curl);
        // Check for errors
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        } else {
            // Print the response
            while (counter <= readBuffer.length()){
                std::cout << "Response:\n" << readBuffer.substr(counter, (readBuffer.find("\r\n\r\n") > readBuffer.length() ? readBuffer.length() : readBuffer.find("\r\n\r\n"))) << std::endl;
                counter = readBuffer.find("\r\n\r\n");
            }

        }

        // Clean up
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return 0;
}

// int main(int ac, char **av){
//     // if (ac != 3) exitError("Wrong number of arguments\n");
    
// }