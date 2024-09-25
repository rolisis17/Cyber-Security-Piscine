import requests

def fetch_url(url) try:
        # Send a GET request to the URL
        response = requests.get(url)
        
        # Check if the request was successful
        if response.status_code == 200:
            print("Response from the server:")
            print(response.text)  # Print the response content
        else:
            print(f"Error: Received status code {response.status_code}")
    except requests.exceptions.RequestException as e:
        print(f"An error occurred: {e}")

# Example usage
if __name__ == "__main__":
    url = input("Enter the URL: ")
    fetch_url(url)