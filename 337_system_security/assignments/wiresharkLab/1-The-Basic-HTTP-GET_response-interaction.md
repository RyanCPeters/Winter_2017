1. The Basic HTTP GET/response interaction
    
    | frame # | time | source ip address | dest ip address | protocol | length | info |
    |:-------:|:----:|:-----------------:|:---------------:|:--------:|:------:|:----:|
    | 350 | 24.607492 | 10.156.9.94 | 128.119.245.12 | HTTP | 488 | GET /wireshark-labs/ |
    | 377 | 24.983861 | 128.119.245.12 | 10.156.9.94 | HTTP | 540 | HTTP/1.1 200 OK  (text/html) |
    
    
    350 24.607492   10.156.9.94 128.119.245.12  HTTP    488 GET /wireshark-labs/HTTP-wireshark-file1.html HTTP/1.1 
        Hypertext Transfer Protocol
        GET /wireshark-labs/HTTP-wireshark-file1.html HTTP/1.1\r\n
            [Expert Info (Chat/Sequence): GET /wireshark-labs/HTTP-wireshark-file1.html HTTP/1.1\r\n]
                [GET /wireshark-labs/HTTP-wireshark-file1.html HTTP/1.1\r\n]
                [Severity level: Chat]
                [Group: Sequence]
            Request Method: GET
            Request URI: /wireshark-labs/HTTP-wireshark-file1.html
            Request Version: HTTP/1.1
        Host: gaia.cs.umass.edu\r\n
        Connection: keep-alive\r\n
        User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/63.0.3239.132 Safari/537.36\r\n
        Upgrade-Insecure-Requests: 1\r\n
        Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8\r\n
        DNT: 1\r\n
        Accept-Encoding: gzip, deflate\r\n
        Accept-Language: en-US,en;q=0.9\r\n
        \r\n
        [Full request URI: http://gaia.cs.umass.edu/wireshark-labs/HTTP-wireshark-file1.html]
        [HTTP request 1/2]
        [Response in frame: 377]
        [Next request in frame: 380]

    377 24.983861   128.119.245.12  10.156.9.94 HTTP    540 HTTP/1.1 200 OK  (text/html)
        Hypertext Transfer Protocol
            HTTP/1.1 200 OK\r\n
                [Expert Info (Chat/Sequence): HTTP/1.1 200 OK\r\n]
                    [HTTP/1.1 200 OK\r\n]
                    [Severity level: Chat]
                    [Group: Sequence]
                Request Version: HTTP/1.1
                Status Code: 200
                [Status Code Description: OK]
                Response Phrase: OK
            Date: Fri, 02 Feb 2018 00:30:33 GMT\r\n
            Server: Apache/2.4.6 (CentOS) OpenSSL/1.0.2k-fips PHP/5.4.16 mod_perl/2.0.10 Perl/v5.16.3\r\n
            Last-Modified: Thu, 01 Feb 2018 06:59:01 GMT\r\n
            ETag: "80-56421217b4b55"\r\n
            Accept-Ranges: bytes\r\n
            Content-Length: 128\r\n
                [Content length: 128]
            Keep-Alive: timeout=5, max=100\r\n
            Connection: Keep-Alive\r\n
            Content-Type: text/html; charset=UTF-8\r\n
            \r\n
            [HTTP response 1/2]
            [Time since request: 0.376369000 seconds]
            [Request in frame: 350]
            [Next request in frame: 380]
            [Next response in frame: 381]
            File Data: 128 bytes
        Line-based text data: text/html
            <html>\n
            Congratulations.  You've downloaded the file \n
            http://gaia.cs.umass.edu/wireshark-labs/HTTP-wireshark-file1.html!\n
            </html>\n



    1. Is your browser running HTTP version 1.0 or 1.1? What version of HTTP is the
    server running?
        - `http/1.1` for both my browser and the server
    2. What languages (if any) does your browser indicate that it can accept to the
    server?
        - `Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*`
        - ` Accept-Language: en-US,en;q=0.9\r\n`
    3. What is the IP address of your computer? Of the gaia.cs.umass.edu server?
        - My computer is masked behind this ip address: `10.156.9.94`
        - gaia ip address: `128.119.245.12`
    4. What is the status code returned from the server to your browser?
        - `Status Code: 200 [Status Code Description: OK]`
    5. When was the HTML file that you are retrieving last modified at the server?
        - `Last-Modified: Thu, 01 Feb 2018 06:59:01 GMT\r\n`
    6. How many bytes of content are being returned to your browser?
        - `File Data: 128 bytes`
    7. By inspecting the raw data in the packet content window, do you see any headers
    within the data that are not displayed in the packet-listing window? If so, name
    one.
        - 
    In your answer to question 5 above, you might have been surprised to find that the
    document you just retrieved was last modified within a minute before you downloaded
    the document. That’s because (for this particular file), the gaia.cs.umass.edu server is
    setting the file’s last-modified time to be the current time, and is doing so once per
    minute. Thus, if you wait a minute between accesses, the file will appear to have been
    recently modified, and hence your browser will download a “new” copy of the document.



let systemd do the the heavy lifting

use systemd sudo systemctl enable sddm

for the graphical interface go with plasma or gnome or xfce or cinnamon

check out the arch wiki for all the 
