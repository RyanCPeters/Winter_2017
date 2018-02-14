Assignment4: Wireshark Analysis
===

Ryan Peters
---

---
1 The Basic HTTP GET/response interaction
---

    
| frame # | time | source ip address | dest ip address | protocol | length | info |
|:-------:|:----:|:-----------------:|:---------------:|:--------:|:------:|:----:|
| 30 | 0.173390 | 192.168.0.102 | 128.119.245.12 | HTTP | 488 | GET /wireshark-labs/HTTP-wireshark-file1.html HTTP/1.1  |
| 32 | 0.262952 | 128.119.245.12 | 192.168.0.102 | HTTP | 540 | HTTP/1.1 200 OK  (text/html) |

---

#### Initial client GET request

```
30  0.173390    192.168.0.102   gaia.cs.umass.edu   HTTP    488 GET /wireshark-labs/HTTP-wireshark-file1.html HTTP/1.1 
    Internet Protocol Version 4, Src: 192.168.0.102 (192.168.0.102), Dst: gaia.cs.umass.edu (128.119.245.12)
        0100 .... = Version: 4
        .... 0101 = Header Length: 20 bytes (5)
        Differentiated Services Field: 0x00 (DSCP: CS0, ECN: Not-ECT)
            0000 00.. = Differentiated Services Codepoint: Default (0)
            .... ..00 = Explicit Congestion Notification: Not ECN-Capable Transport (0)
        Total Length: 474
        Identification: 0x06d0 (1744)
        Flags: 0x02 (Don't Fragment)
            0... .... = Reserved bit: Not set
            .1.. .... = Don't fragment: Set
            ..0. .... = More fragments: Not set
        Fragment offset: 0
        Time to live: 128
        Protocol: TCP (6)
        Header checksum: 0x0000 [validation disabled]
        [Header checksum status: Unverified]
        Source: 192.168.0.102 (192.168.0.102)
        Destination: gaia.cs.umass.edu (128.119.245.12)
        [Source GeoIP: Unknown]
        [Destination GeoIP: Unknown] 
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
        [Response in frame: 32]
        [Next request in frame: 33]
``` 

#### Host server response   
   
```        
32  0.262952    gaia.cs.umass.edu   192.168.0.102   HTTP    540 HTTP/1.1 200 OK  (text/html)
    Internet Protocol Version 4, Src: gaia.cs.umass.edu (128.119.245.12), Dst: 192.168.0.102 (192.168.0.102)
        0100 .... = Version: 4
        .... 0101 = Header Length: 20 bytes (5)
        Differentiated Services Field: 0x20 (DSCP: CS1, ECN: Not-ECT)
            0010 00.. = Differentiated Services Codepoint: Class Selector 1 (8)
            .... ..00 = Explicit Congestion Notification: Not ECN-Capable Transport (0)
        Total Length: 526
        Identification: 0x8a15 (35349)
        Flags: 0x02 (Don't Fragment)
            0... .... = Reserved bit: Not set
            .1.. .... = Don't fragment: Set
            ..0. .... = More fragments: Not set
        Fragment offset: 0
        Time to live: 46
        Protocol: TCP (6)
        Header checksum: 0x8a22 [validation disabled]
        [Header checksum status: Unverified]
        Source: gaia.cs.umass.edu (128.119.245.12)
        Destination: 192.168.0.102 (192.168.0.102)
        [Source GeoIP: Unknown]
        [Destination GeoIP: Unknown]
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
        Date: Wed, 14 Feb 2018 04:21:07 GMT\r\n
        Server: Apache/2.4.6 (CentOS) OpenSSL/1.0.2k-fips PHP/5.4.16 mod_perl/2.0.10 Perl/v5.16.3\r\n
        Last-Modified: Tue, 13 Feb 2018 06:59:01 GMT\r\n
        ETag: "80-56512878d164b"\r\n
        Accept-Ranges: bytes\r\n
        Content-Length: 128\r\n
            [Content length: 128]
        Keep-Alive: timeout=5, max=100\r\n
        Connection: Keep-Alive\r\n
        Content-Type: text/html; charset=UTF-8\r\n
        \r\n
        [HTTP response 1/2]
        [Time since request: 0.089562000 seconds]
        [Request in frame: 30]
        [Next request in frame: 33]
        [Next response in frame: 34]
        File Data: 128 bytes  
```  

---

1. Is your browser running HTTP version 1.0 or 1.1? What version of HTTP is the server running?
    + From line 42 of this document: `Request Version: HTTP/1.1` 
2. What languages (if any) does your browser indicate that it can accept to the server?
    + From line 50 of this document: `Accept-Language: en-US,en;q=0.9\r\n`
3. What is the IP address of your computer? Of the gaia.cs.umass.edu server?
    + From line 12 of this document: `Internet Protocol Version 4, Src: 192.168.0.102 (192.168.0.102), Dst: gaia.cs.umass.edu (128.119.245.12)`
        + My computer IP address: `192.168.0.102`
        + umass.edu server IP address: `128.119.245.12`
4. What is the status code returned from the server to your browser?
    + From line 90 of this document: `Status Code: 200`
5. When was the HTML file that you are retrieving last modified at the server?
    + From line 95 of this document: `Last-Modified: Tue, 13 Feb 2018 06:59:01 GMT\r\n`
6. How many bytes of content are being returned to your browser?
    + From lines 98 of this document: `Content-Length: 128\r\n`
7. By inspecting the raw data in the packet content window, do you see any headers within the data that are not displayed in the packet-listing window? If so, name one.
    + I checked each hex value in the raw data and found no additional headers.

![](./images/problem1-1.png)

![](./images/problem1-2.png)

---
2 The HTTP CONDITIONAL GET/response interaction
---

| frame # | time | source ip address | dest ip address | protocol | length | info |
|:-------:|:----:|:-----------------:|:---------------:|:--------:|:------:|:----:|
| 67 | 20.044479 | 192.168.0.102 | 128.119.245.12 | HTTP | 488 |  GET /wireshark-labs/HTTP-wireshark-file2.html HTTP/1.1  |
| 69 | 20.044479 | 128.119.245.12 | 192.168.0.102 | HTTP | 784 | HTTP/1.1 200 OK  (text/html) |
|235| 38.303059   |192.168.0.102   |128.119.245.12   |HTTP    |600| GET /wireshark-labs/HTTP-wireshark-file2.html HTTP/1.1|
|237| 38.394623   |128.119.245.12|   192.168.0.102|   HTTP    |294| HTTP/1.1 304 Not Modified|

---

#### Initial client GET request

```
67  20.044479   192.168.0.102   128.119.245.12  HTTP    488 GET /wireshark-labs/HTTP-wireshark-file2.html HTTP/1.1 
    Hypertext Transfer Protocol
        GET /wireshark-labs/HTTP-wireshark-file2.html HTTP/1.1\r\n
            [Expert Info (Chat/Sequence): GET /wireshark-labs/HTTP-wireshark-file2.html HTTP/1.1\r\n]
                [GET /wireshark-labs/HTTP-wireshark-file2.html HTTP/1.1\r\n]
                [Severity level: Chat]
                [Group: Sequence]
            Request Method: GET
            Request URI: /wireshark-labs/HTTP-wireshark-file2.html
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
        [Full request URI: http://gaia.cs.umass.edu/wireshark-labs/HTTP-wireshark-file2.html]
        [HTTP request 1/2]
        [Response in frame: 69]
        [Next request in frame: 71]
```

#### Host server response

```
69  20.131291   128.119.245.12  192.168.0.102   HTTP    784 HTTP/1.1 200 OK  (text/html)
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
        Date: Wed, 14 Feb 2018 05:17:35 GMT\r\n
        Server: Apache/2.4.6 (CentOS) OpenSSL/1.0.2k-fips PHP/5.4.16 mod_perl/2.0.10 Perl/v5.16.3\r\n
        Last-Modified: Tue, 13 Feb 2018 06:59:01 GMT\r\n
        ETag: "173-56512878d0e7b"\r\n
        Accept-Ranges: bytes\r\n
        Content-Length: 371\r\n
            [Content length: 371]
        Keep-Alive: timeout=5, max=100\r\n
        Connection: Keep-Alive\r\n
        Content-Type: text/html; charset=UTF-8\r\n
        \r\n
        [HTTP response 1/2]
        [Time since request: 0.086812000 seconds]
        [Request in frame: 67]
        [Next request in frame: 71]
        [Next response in frame: 72]
        File Data: 371 bytes
    Line-based text data: text/html
        \n
        <html>\n
        \n
        Congratulations again!  Now you've downloaded the file lab2-2.html. <br>\n
        This file's last modification date will not change.  <p>\n
        Thus  if you download this multiple times on your browser, a complete copy <br>\n
        will only be sent once by the server due to the inclusion of the IN-MODIFIED-SINCE<br>\n
        field in your browser's HTTP GET request to the server.\n
        \n
        </html>\n

```

---
---

#### Second client GET request

```
235 38.303059   192.168.0.102   gaia.cs.umass.edu   HTTP    600 GET /wireshark-labs/HTTP-wireshark-file2.html HTTP/1.1 
    Hypertext Transfer Protocol
        GET /wireshark-labs/HTTP-wireshark-file2.html HTTP/1.1\r\n
            [Expert Info (Chat/Sequence): GET /wireshark-labs/HTTP-wireshark-file2.html HTTP/1.1\r\n]
                [GET /wireshark-labs/HTTP-wireshark-file2.html HTTP/1.1\r\n]
                [Severity level: Chat]
                [Group: Sequence]
            Request Method: GET
            Request URI: /wireshark-labs/HTTP-wireshark-file2.html
            Request Version: HTTP/1.1
        Host: gaia.cs.umass.edu\r\n
        Connection: keep-alive\r\n
        Cache-Control: max-age=0\r\n
        User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/63.0.3239.132 Safari/537.36\r\n
        Upgrade-Insecure-Requests: 1\r\n
        Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8\r\n
        DNT: 1\r\n
        Accept-Encoding: gzip, deflate\r\n
        Accept-Language: en-US,en;q=0.9\r\n
        If-None-Match: "173-56512878d0e7b"\r\n
        If-Modified-Since: Tue, 13 Feb 2018 06:59:01 GMT\r\n
        \r\n
        [Full request URI: http://gaia.cs.umass.edu/wireshark-labs/HTTP-wireshark-file2.html]
        [HTTP request 1/1]
        [Response in frame: 237]
```

#### Host server response

```
237 38.394623   gaia.cs.umass.edu   192.168.0.102   HTTP    294 HTTP/1.1 304 Not Modified 
    Hypertext Transfer Protocol
        HTTP/1.1 304 Not Modified\r\n
            [Expert Info (Chat/Sequence): HTTP/1.1 304 Not Modified\r\n]
                [HTTP/1.1 304 Not Modified\r\n]
                [Severity level: Chat]
                [Group: Sequence]
            Request Version: HTTP/1.1
            Status Code: 304
            [Status Code Description: Not Modified]
            Response Phrase: Not Modified
        Date: Wed, 14 Feb 2018 05:17:53 GMT\r\n
        Server: Apache/2.4.6 (CentOS) OpenSSL/1.0.2k-fips PHP/5.4.16 mod_perl/2.0.10 Perl/v5.16.3\r\n
        Connection: Keep-Alive\r\n
        Keep-Alive: timeout=5, max=100\r\n
        ETag: "173-56512878d0e7b"\r\n
        \r\n
        [HTTP response 1/1]
        [Time since request: 0.091564000 seconds]
        [Request in frame: 235]
```

---

8. Inspect the contents of the first HTTP GET request from your browser to the server. Do you see an “IF-MODIFIED-SINCE” line in the HTTP GET?
    + No, The `IF-MODIFIED-SINCE` line doesn't appear in any frame until `frame#235` when the page was refreshed.
9. Inspect the contents of the server response. Did the server explicitly return the contents of the file? How can you tell?
    + Yes it did, because its response included an observable file that was 371 bytes in length.
        + See line 205 of this document.
10. Now inspect the contents of the second HTTP GET request from your browser to the server. Do you see an “IF-MODIFIED-SINCE:” line in the HTTP GET? If so, what information follows the “IF-MODIFIED-SINCE:” header?
    + From line 257 of this document: `If-Modified-Since: Tue, 13 Feb 2018 06:59:01 GMT\r\n`
11. What is the HTTP status code and phrase returned from the server in response to this second HTTP GET? Did the server explicitly return the contents of the file? Explain.
    + from lines 275, 276, and 277 of this document: `Status Code: 304`, `[Status Code Description: Not Modified]`, `Response Phrase: Not Modified`
    + No, the server did not return the contents of the unmodified file. There was no file attached to this frame.

![](./images/problem2-1.png)

---
3 Retrieving Long Documents
---
    
| frame # | time | source ip address | dest ip address | protocol | length | info |
|:-------:|:----:|:-----------------:|:---------------:|:--------:|:------:|:----:|
|5|   0.001832|    192.168.0.102|   192.168.0.103|   HTTP|    282| GET /spConn?action=getInfo HTTP/1.1|
|6|   0.008067|    192.168.0.103|   192.168.0.102|   HTTP|    433| HTTP/1.1 200 OK  (application/json)|
|45|  4.001991|    192.168.0.102|   gaia.cs.umass.edu|   HTTP|    488| GET /wireshark-labs/HTTP-wireshark-file3.html HTTP/1.1|
|55|  4.091825|    gaia.cs.umass.edu|   192.168.0.102|   HTTP|    537| HTTP/1.1 200 OK  (text/html)|

---

#### Initial client GET request

- This first exchange looks odd to me, it's as if my computer is communicating with another entity on my home network.

```
5   0.001832    192.168.0.102   192.168.0.103   HTTP    282 GET /spConn?action=getInfo HTTP/1.1 
    Hypertext Transfer Protocol
        GET /spConn?action=getInfo HTTP/1.1\r\n
            [Expert Info (Chat/Sequence): GET /spConn?action=getInfo HTTP/1.1\r\n]
                [GET /spConn?action=getInfo HTTP/1.1\r\n]
                [Severity level: Chat]
                [Group: Sequence]
            Request Method: GET
            Request URI: /spConn?action=getInfo
                Request URI Path: /spConn
                Request URI Query: action=getInfo
                    Request URI Query Parameter: action=getInfo
            Request Version: HTTP/1.1
        Host: 192.168.0.103:41800\r\n
        Keep-Alive: 0\r\n
        Connection: keep-alive\r\n
        Accept-Encoding: gzip\r\n
        Content-Type: application/x-www-form-urlencoded\r\n
        user-agent: Spotify/107300345 Win32/0 (PC laptop)\r\n
        \r\n
        [Full request URI: http://192.168.0.103:41800/spConn?action=getInfo]
        [HTTP request 1/1]
        [Response in frame: 6]
```

#### Host response

- Note that as stated above, this first exchange appears to be between my computer and a local point in my home network.

```
6   0.008067    192.168.0.103   192.168.0.102   HTTP    433 HTTP/1.1 200 OK  (application/json)
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
        Content-Type: application/json\r\n
        Content-Length: 307\r\n
            [Content length: 307]
        \r\n
        [HTTP response 1/1]
        [Time since request: 0.006235000 seconds]
        [Request in frame: 5]
        File Data: 307 bytes
    JavaScript Object Notation: application/json
        Object
            Member Key: accountReq
                String value: FREE
                Key: accountReq
            Member Key: activeUser
                String value: 
                Key: activeUser
            Member Key: availability
                String value: UNAVAILABLE
                Key: availability
            Member Key: brandDisplayName
                String value: sony_tv
                Key: brandDisplayName
            Member Key: deviceID
                String value: 90b19a4f624c2183e1e9d39a4b98e075edbad36f
                Key: deviceID
            Member Key: deviceType
                String value: GAMECONSOLE
                Key: deviceType
            Member Key: modelDisplayName
                String value: ps4
                Key: modelDisplayName
            Member Key: publicKey
                String value: 
                Key: publicKey
            Member Key: remoteName
                String value: PS4-156
                Key: remoteName
            Member Key: spotifyError
                Number value: 0
                Key: spotifyError
            Member Key: status
                Number value: 101
                Key: status
            Member Key: statusString
                String value: OK
                Key: statusString
            Member Key: version
                String value: 2.2.2
                Key: version
```

---
---

#### Second client GET request

```
45  4.001991    192.168.0.102   gaia.cs.umass.edu   HTTP    488 GET /wireshark-labs/HTTP-wireshark-file3.html HTTP/1.1 
    Hypertext Transfer Protocol
        GET /wireshark-labs/HTTP-wireshark-file3.html HTTP/1.1\r\n
            [Expert Info (Chat/Sequence): GET /wireshark-labs/HTTP-wireshark-file3.html HTTP/1.1\r\n]
                [GET /wireshark-labs/HTTP-wireshark-file3.html HTTP/1.1\r\n]
                [Severity level: Chat]
                [Group: Sequence]
            Request Method: GET
            Request URI: /wireshark-labs/HTTP-wireshark-file3.html
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
        [Full request URI: http://gaia.cs.umass.edu/wireshark-labs/HTTP-wireshark-file3.html]
        [HTTP request 1/2]
        [Response in frame: 55]
        [Next request in frame: 57]
```

#### Host server response
```
55  4.091825    gaia.cs.umass.edu   192.168.0.102   HTTP    537 HTTP/1.1 200 OK  (text/html)
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
        Date: Wed, 14 Feb 2018 06:15:02 GMT\r\n
        Server: Apache/2.4.6 (CentOS) OpenSSL/1.0.2k-fips PHP/5.4.16 mod_perl/2.0.10 Perl/v5.16.3\r\n
        Last-Modified: Wed, 14 Feb 2018 06:15:02 GMT\r\n
        ETag: W/"1194-565260810c8b4"\r\n
        Accept-Ranges: bytes\r\n
        Content-Length: 4500\r\n
            [Content length: 4500]
        Keep-Alive: timeout=5, max=100\r\n
        Connection: Keep-Alive\r\n
        Content-Type: text/html; charset=UTF-8\r\n
        \r\n
        [HTTP response 1/2]
        [Time since request: 0.089834000 seconds]
        [Request in frame: 45]
        [Next request in frame: 57]
        [Next response in frame: 58]
        File Data: 4500 bytes
    Line-based text data: text/html
        <html><head> \n
        <title>Historical Documents:THE BILL OF RIGHTS</title></head>\n
        \n
        \n
        <body bgcolor="#ffffff" link="#330000" vlink="#666633">\n
        <p><br>\n
        </p>\n
        <p></p><center><b>THE BILL OF RIGHTS</b><br>\n
          <em>Amendments 1-10 of the Constitution</em>\n
        </center>\n
        \n
        <p>The Conventions of a number of the States having, at the time of adopting\n
        the Constitution, expressed a desire, in order to prevent misconstruction\n
        or abuse of its powers, that further declaratory and restrictive clauses\n
        should be added, and as extending the ground of public confidence in the\n
        Government will best insure the beneficent ends of its institution; </p><p>  Resolved, by the Senate and House of Representatives of the United\n
        States of America, in Congress assembled, two-thirds of both Houses concurring,\n
        that the following articles be proposed to the Legislatures of the several\n
        States, as amendments to the Constitution of the United States; all or any\n
        of which articles, when ratified by three-fourths of the said Legislatures,\n
        to be valid to all intents and purposes as part of the said Constitution,\n
        namely:    </p><p><a name="1"><strong><h3>Amendment I</h3></strong></a>\n
        \n
        <p></p><p>Congress shall make no law respecting an establishment of\n
        religion, or prohibiting the free exercise thereof; or\n
        abridging the freedom of speech, or of the press; or the\n
        right of the people peaceably to assemble, and to petition\n
        the government for a redress of grievances.\n
        \n
        </p><p><a name="2"><strong><h3>Amendment II</h3></strong></a>\n
        \n
        <p></p><p>A well regulated militia, being necessary to the security\n
        of a free state, the right of the people to keep and bear\n
        arms, shall not be infringed.\n
        \n
        </p><p><a name="3"><strong><h3>Amendment III</h3></strong></a>\n
        \n
        <p></p><p>No soldier shall, in time of peace be quartered in any house,\n
        without the consent of the owner, nor in time of war, but\n
        in a manner to be prescribed by law.\n
        \n
        </p><p><a name="4"><strong><h3>Amendment IV</h3></strong></a>\n
        \n
        <p></p><p>The right of the people to be secure in their persons, houses,\n
        papers, and effects, against unreasonable searches and seizures,\n
        shall not be violated, and no warrants shall issue, but upon\n
        probable cause, supported by oath or affirmation, and\n
        particularly describing the place to be searched, and the\n
        persons or things to be seized.\n
        \n
        </p><p><a name="5"><strong><h3>Amendment V</h3></strong></a>\n
        \n
        <p></p><p>No person shall be held to answer for a capital, or otherwise\n
        infamous crime, unless on a presentment or indictment of a grand\n
        jury, except in cases arising in the land or naval forces,\n
        or in the militia, when in actual service in time of war\n
        or public danger; nor shall any person be subject for the\n
        same offense to be twice put in jeopardy of life or limb;\n
        nor shall be compelled in any criminal case to be a witness\n
        against himself, nor be deprived of life, liberty, or property,\n
        without due process of law; nor shall private property be\n
        taken for public use, without just compensation.\n
        \n
        </p><p><a name="6"><strong><h3>Amendment VI</h3></strong></a>\n
        \n
        <p></p><p>In all criminal prosecutions, the accused shall enjoy the right\n
        to a speedy and public trial, by an impartial jury of the state\n
        and district wherein the crime shall have been committed, which\n
        district shall have been previously ascertained by law, and\n
        to be informed of the nature and cause of the accusation;\n
        to be confronted with the witnesses against him; to have\n
        compulsory process for obtaining witnesses in his favor,\n
        and to have the assistance of counsel for his defense.\n
        \n
        </p><p><a name="7"><strong><h3>Amendment VII</h3></strong></a>\n
        \n
        <p></p><p>In suits at common law, where the value in controversy shall\n
        exceed twenty dollars, the right of trial by jury shall be\n
        preserved, and no fact tried by a jury, shall be otherwise\n
        reexamined in any court of the United States, than according\n
        to the rules of the common law.\n
        \n
        </p><p><a name="8"><strong><h3>Amendment VIII</h3></strong></a>\n
        \n
        <p></p><p>Excessive bail shall not be required, nor excessive fines\n
        imposed, nor cruel and unusual punishments inflicted.\n
        \n
        </p><p><a name="9"><strong><h3>Amendment IX</h3></strong></a>\n
        \n
        <p></p><p>The enumeration in the Constitution, of certain rights, shall\n
        not be construed to deny or disparage others retained by the people.\n
        \n
        </p><p><a name="10"><strong><h3>Amendment X</h3></strong></a>\n
        \n
        <p></p>\n
        <p>The powers not delegated to the United States by the Constitution, nor prohibited \n
          by it to the states, are reserved to the states respectively, or to the people.</p>\n
        </body></html>
```

---

12. How many HTTP GET request messages did your browser send? Which packet number in the trace contains the GET message for the Bill or Rights?
    + 
13. Which packet number in the trace contains the status code and phrase associated with the response to the HTTP GET request?
    + 
14. What is the status code and phrase in the response?
    + 
15. How many data-containing TCP segments were needed to carry the single HTTP response and the text of the Bill of Rights?
    + 

![](./images/problem3-1.png)

---
4 HTML Documents with Embedded Objects
---
