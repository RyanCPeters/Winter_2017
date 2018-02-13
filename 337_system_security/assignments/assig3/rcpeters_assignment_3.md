CSS337: Secure Systems
===

Assignment 3: DNS Exploration
---

- Pick a domain, and using the following tools that can query DNS, explore what you can learn about that domain. Recommended tools are `nslookup`, `dig` and `whois`.
  + chosen domain is `chegg.com`


1. What common host names are on the network?
  + All available host servers are through AWS, with different org tags for different regional boundaries.
    * The following host names are consistent across each recon tool.
  + `chegg.com       nameserver = ns-1026.awsdns-00.org`
  + `chegg.com       nameserver = ns-2045.awsdns-63.co.uk`
  + `chegg.com       nameserver = ns-289.awsdns-36.com`
  + `chegg.com       nameserver = ns-699.awsdns-23.net`
2. If you look up a host name, and then do a reverse lookup from the IP to the host
name, are they the same?
  + Not in this case as `chegg` is hosted through `AWS`. This means that the specific IP address for the hosting server will direct us to Amazon's hosting servers that are responsible for handling chegg's web traffic.
3. What can you learn about the mail servers? Are they managed by that organization,
or do they look like they're hosted?
  + They appear to be hosted by an outfit with domain name `messagelabs.com`
4. What other information are you able to learn?
  + as per the code block that immediately follows (information acquired via `whois` tool)
  ```
      Registry Registrant ID:
        Registrant Name: Domain Administrator
        Registrant Organization: Chegg Inc.
        Registrant Street: 3990 Freedom Circle,
        Registrant City: Santa Clara
        Registrant State/Province: CA
        Registrant Postal Code: 95054
        Registrant Country: US
        Registrant Phone: +1.4088555700
        Registrant Phone Ext:
        Registrant Fax:
        Registrant Fax Ext:
        Registrant Email: domainrenewals@chegg.com
      Registry Admin ID:
        Admin Name: Domain Administrator
        Admin Organization: Chegg Inc.
        Admin Street: 3990 Freedom Circle,
        Admin City: Santa Clara
        Admin State/Province: CA
        Admin Postal Code: 95054
        Admin Country: US
        Admin Phone: +1.4088555700
        Admin Phone Ext:
        Admin Fax:
        Admin Fax Ext:
        Admin Email: domainrenewals@chegg.com
      Registry Tech ID:
        Tech Name: Domain Administrator
        Tech Organization: Chegg Inc.
        Tech Street: 3990 Freedom Circle,
        Tech City: Santa Clara
        Tech State/Province: CA
        Tech Postal Code: 95054
        Tech Country: US
        Tech Phone: +1.4088555700
        Tech Phone Ext:
        Tech Fax:
        Tech Fax Ext:
        Tech Email: domainrenewals@chegg.com
  ```
  + We learned the physical location of the company's headquarters, and their contact phone number and email... Pretty lame I admit.
  + We also learned that services hosted through AWS are hard targets for network reconnaissance 


### Additional note on submission materials:

I found it rather difficult to keep the many screen-shot saved images straight with how they related to each question as I experimented in the command console using the various recon tools. 

So, instead of submit an incoherent mess of screen images from my time spent on the assignment, I created the following block quotes which I copy pasted into this document as I went along.

Because I had to do some rather janky workarounds to get the tools to work right in my windows computer -- my Linux install kind of broke when I was attempting to convert it from Ubuntu to Arch Linux distro last week -- **I omitted some of the output** from when I was experimenting with installation and output validation tutorials on the web. 


nslookup command line output for chegg.com
<blockquote>
  Microsoft Windows [Version 10.0.16299.192]
  (c) 2017 Microsoft Corporation. All rights reserved.

  C:\Users\Peter>nslookup
    Default Server:  UnKnown
    Address:  192.168.0.1

    > chegg.com
    Server:  UnKnown
    Address:  192.168.0.1

    Non-authoritative answer:
    Name:    chegg.com
    Addresses:  50.112.145.222
              54.236.238.201

    > set type=mx
    > chegg.com
    Server:  UnKnown
    Address:  192.168.0.1

    Non-authoritative answer:
    chegg.com       MX preference = 20, mail exchanger = cluster6a.us.messagelabs.com
    chegg.com       MX preference = 10, mail exchanger = cluster6.us.messagelabs.com
    > set type=a
    > chegg.com
    Server:  UnKnown
    Address:  192.168.0.1

    Non-authoritative answer:
    Name:    chegg.com
    Addresses:  50.112.145.222
              54.236.238.201

    > set type=txt
    > chegg.com
    Server:  UnKnown
    Address:  192.168.0.1

    Non-authoritative answer:
    chegg.com       text =

            "google-site-verification=toj1VRJpvynNZoKUzR-m5A2dSOvkGUhIy41XdUWfAC8"
    chegg.com       text =

            "v=spf1 include:spf-sml.chegg.com include:spf-v.chegg.com include:spf.protection.outlook.com include:spf.clearslide.com ip4:199.58.140.0/22 include:_spf.jobvite.com include:smarteru.com include:neovation.com ~all"
    > set type=ns
    > chegg.com
    Server:  UnKnown
    Address:  192.168.0.1

    Non-authoritative answer:
    chegg.com       nameserver = ns-1026.awsdns-00.org
    chegg.com       nameserver = ns-2045.awsdns-63.co.uk
    chegg.com       nameserver = ns-289.awsdns-36.com
    chegg.com       nameserver = ns-699.awsdns-23.net

    ns-1026.awsdns-00.org   internet address = 205.251.196.2
    ns-1026.awsdns-00.org   AAAA IPv6 address = 2600:9000:5304:200::1
    ns-2045.awsdns-63.co.uk internet address = 205.251.199.253
    ns-2045.awsdns-63.co.uk AAAA IPv6 address = 2600:9000:5307:fd00::1
    ns-289.awsdns-36.com    internet address = 205.251.193.33
    ns-289.awsdns-36.com    AAAA IPv6 address = 2600:9000:5301:2100::1
    ns-699.awsdns-23.net    internet address = 205.251.194.187
    ns-699.awsdns-23.net    AAAA IPv6 address = 2600:9000:5302:bb00::1
    >
</blockquote>

dig command line output for chegg.com
<blockquote>
  C:\Users\Peter\GitHub_remotes\dig_win64_distro>dig

    ; <<>> DiG 9.10.6-P1 <<>>
    ;; global options: +cmd
    ;; Got answer:
    ;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 23728
    ;; flags: qr rd ra ad; QUERY: 1, ANSWER: 13, AUTHORITY: 0, ADDITIONAL: 26

    ;; OPT PSEUDOSECTION:
    ; EDNS: version: 0, flags:; udp: 512
    ;; QUESTION SECTION:
    ;.                              IN      NS

    ;; ANSWER SECTION:
    .                       500335  IN      NS      c.root-servers.net.
    .                       500335  IN      NS      h.root-servers.net.
    .                       500335  IN      NS      f.root-servers.net.
    .                       500335  IN      NS      l.root-servers.net.
    .                       500335  IN      NS      m.root-servers.net.
    .                       500335  IN      NS      d.root-servers.net.
    .                       500335  IN      NS      g.root-servers.net.
    .                       500335  IN      NS      j.root-servers.net.
    .                       500335  IN      NS      k.root-servers.net.
    .                       500335  IN      NS      i.root-servers.net.
    .                       500335  IN      NS      b.root-servers.net.
    .                       500335  IN      NS      a.root-servers.net.
    .                       500335  IN      NS      e.root-servers.net.

    ;; ADDITIONAL SECTION:
    e.root-servers.net.     576355  IN      A       192.203.230.10
    e.root-servers.net.     376077  IN      AAAA    2001:500:a8::e
    c.root-servers.net.     577522  IN      A       192.33.4.12
    h.root-servers.net.     572178  IN      A       198.97.190.53
    h.root-servers.net.     466711  IN      AAAA    2001:500:1::53
    f.root-servers.net.     577038  IN      A       192.5.5.241
    f.root-servers.net.     500548  IN      AAAA    2001:500:2f::f
    l.root-servers.net.     572178  IN      A       199.7.83.42
    l.root-servers.net.     103917  IN      AAAA    2001:500:9f::42
    m.root-servers.net.     570549  IN      A       202.12.27.33
    m.root-servers.net.     570882  IN      AAAA    2001:dc3::35
    d.root-servers.net.     580744  IN      A       199.7.91.13
    d.root-servers.net.     179972  IN      AAAA    2001:500:2d::d
    g.root-servers.net.     575780  IN      A       192.112.36.4
    g.root-servers.net.     376644  IN      AAAA    2001:500:12::d0d
    j.root-servers.net.     576385  IN      A       192.58.128.30
    j.root-servers.net.     300381  IN      AAAA    2001:503:c27::2:30
    k.root-servers.net.     573545  IN      A       193.0.14.129
    k.root-servers.net.     462876  IN      AAAA    2001:7fd::1
    i.root-servers.net.     573545  IN      A       192.36.148.17
    i.root-servers.net.     447006  IN      AAAA    2001:7fe::53
    b.root-servers.net.     575457  IN      A       199.9.14.201
    b.root-servers.net.     265285  IN      AAAA    2001:500:200::b
    a.root-servers.net.     570533  IN      A       198.41.0.4
    a.root-servers.net.     570852  IN      AAAA    2001:503:ba3e::2:30

    ;; Query time: 12 msec
    ;; SERVER: 192.168.0.1#53(192.168.0.1)
    ;; WHEN: Tue Feb 13 13:14:58 Pacific Standard Time 2018
    ;; MSG SIZE  rcvd: 783
  
  C:\Users\Peter\GitHub_remotes\dig_win64_distro>dig @50.112.145.222

    ; <<>> DiG 9.10.6-P1 <<>> @50.112.145.222
    ; (1 server found)
    ;; global options: +cmd
    ;; connection timed out; no servers could be reached

    C:\Users\Peter\GitHub_remotes\dig_win64_distro>dig @50.112.145.222 chegg.com -t AXFR
    ;; Connection to 50.112.145.222#53(50.112.145.222) for chegg.com failed: timed out.
    ;; Connection to 50.112.145.222#53(50.112.145.222) for chegg.com failed: timed out.

    ; <<>> DiG 9.10.6-P1 <<>> @50.112.145.222 chegg.com -t AXFR
    ; (1 server found)
    ;; global options: +cmd
    ;; connection timed out; no servers could be reached
    ;; Connection to 50.112.145.222#53(50.112.145.222) for chegg.com failed: timed out.
</blockquote>


whois command line output for chegg.com
<blockquote>
  C:\Users\Peter\GitHub_remotes\whois_install>whois

    Whois v1.20 - Domain information lookup
    Copyright (C) 2005-2017 Mark Russinovich
    Sysinternals - www.sysinternals.com


    Usage: whois [-v] domainname [whois.server]
     -v   Print whois information for referrals
     -nobanner
          Do not display the startup banner and copyright message.
    
  C:\Users\Peter\GitHub_remotes\whois_install>whois -nobanner chegg.com
    Connecting to COM.whois-servers.net...

    WHOIS Server: whois.markmonitor.com
     Registrar URL: http://www.markmonitor.com
     Updated Date: 2015-06-17T17:06:44Z
     Creation Date: 2000-02-23T00:22:32Z
     Registry Expiry Date: 2024-02-23T00:22:32Z
     Registrar: MarkMonitor Inc.
     Registrar IANA ID: 292
     Registrar Abuse Contact Email: abusecomplaints@markmonitor.com
     Registrar Abuse Contact Phone: +1.2083895740
     Domain Status: clientDeleteProhibited https://icann.org/epp#clientDeleteProhibited
     Domain Status: clientTransferProhibited https://icann.org/epp#clientTransferProhibited
     Domain Status: clientUpdateProhibited https://icann.org/epp#clientUpdateProhibited
     Name Server: NS-1026.AWSDNS-00.ORG
     Name Server: NS-2045.AWSDNS-63.CO.UK
     Name Server: NS-289.AWSDNS-36.COM
     Name Server: NS-699.AWSDNS-23.NET
     DNSSEC: unsigned
     URL of the ICANN Whois Inaccuracy Complaint Form: https://www.icann.org/wicf/
    >>> Last update of whois database: 2018-02-13T21:23:22Z <<<

    For more information on Whois status codes, please visit https://icann.org/epp

      NOTICE: The expiration date displayed in this record is the date the
      registrar's sponsorship of the domain name registration in the registry is
      currently set to expire. This date does not necessarily reflect the expiration
      date of the domain name registrant's agreement with the sponsoring
      registrar.  Users may consult the sponsoring registrar's Whois database to
      view the registrar's reported date of expiration for this registration.

      TERMS OF USE: You are not authorized to access or query our Whois
      database through the use of electronic processes that are high-volume and
      automated except as reasonably necessary to register domain names or
      modify existing registrations; the Data in VeriSign Global Registry
      Services' ("VeriSign") Whois database is provided by VeriSign for
      information purposes only, and to assist persons in obtaining information
      about or related to a domain name registration record. VeriSign does not
      guarantee its accuracy. By submitting a Whois query, you agree to abide
      by the following terms of use: You agree that you may use this Data only
      for lawful purposes and that under no circumstances will you use this Data
      to: (1) allow, enable, or otherwise support the transmission of mass
      unsolicited, commercial advertising or solicitations via e-mail, telephone,
      or facsimile; or (2) enable high volume, automated, electronic processes
      that apply to VeriSign (or its computer systems). The compilation,
      repackaging, dissemination or other use of this Data is expressly
      prohibited without the prior written consent of VeriSign. You agree not to
      use electronic processes that are automated and high-volume to access or
      query the Whois database except as reasonably necessary to register
      domain names or modify existing registrations. VeriSign reserves the right
      to restrict your access to the Whois database in its sole discretion to ensure
      operational stability.  VeriSign may restrict or terminate your access to the
      Whois database for failure to abide by these terms of use. VeriSign
      reserves the right to modify these terms at any time.

      The Registry database contains ONLY .COM, .NET, .EDU domains and
      Registrars.

    Connecting to whois.markmonitor.com...

      WHOIS Server: whois.markmonitor.com
      Registrar URL: http://www.markmonitor.com
      Updated Date: 2017-08-02T04:00:04-0700
      Creation Date: 2000-02-22T16:22:32-0800
      Registrar Registration Expiration Date: 2024-02-22T16:22:32-0800
      Registrar: MarkMonitor, Inc.
      Registrar IANA ID: 292
      Registrar Abuse Contact Email: abusecomplaints@markmonitor.com
      Registrar Abuse Contact Phone: +1.2083895740
      Domain Status: clientUpdateProhibited (https://www.icann.org/epp#clientUpdateProhibited)
      Domain Status: clientTransferProhibited (https://www.icann.org/epp#clientTransferProhibited)
      Domain Status: clientDeleteProhibited (https://www.icann.org/epp#clientDeleteProhibited)
    Registry Registrant ID:
      Registrant Name: Domain Administrator
      Registrant Organization: Chegg Inc.
      Registrant Street: 3990 Freedom Circle,
      Registrant City: Santa Clara
      Registrant State/Province: CA
      Registrant Postal Code: 95054
      Registrant Country: US
      Registrant Phone: +1.4088555700
      Registrant Phone Ext:
      Registrant Fax:
      Registrant Fax Ext:
      Registrant Email: domainrenewals@chegg.com
    Registry Admin ID:
      Admin Name: Domain Administrator
      Admin Organization: Chegg Inc.
      Admin Street: 3990 Freedom Circle,
      Admin City: Santa Clara
      Admin State/Province: CA
      Admin Postal Code: 95054
      Admin Country: US
      Admin Phone: +1.4088555700
      Admin Phone Ext:
      Admin Fax:
      Admin Fax Ext:
      Admin Email: domainrenewals@chegg.com
    Registry Tech ID:
      Tech Name: Domain Administrator
      Tech Organization: Chegg Inc.
      Tech Street: 3990 Freedom Circle,
      Tech City: Santa Clara
      Tech State/Province: CA
      Tech Postal Code: 95054
      Tech Country: US
      Tech Phone: +1.4088555700
      Tech Phone Ext:
      Tech Fax:
      Tech Fax Ext:
      Tech Email: domainrenewals@chegg.com
    Name Server: ns-699.awsdns-23.net
    Name Server: ns-1026.awsdns-00.org
    Name Server: ns-2045.awsdns-63.co.uk
    Name Server: ns-289.awsdns-36.com
    DNSSEC: unsigned
    URL of the ICANN WHOIS Data Problem Reporting System: http://wdprs.internic.net/
    >>> Last update of WHOIS database: 2018-02-13T13:23:33-0800 <<<

      The Data in MarkMonitor.com's WHOIS database is provided by MarkMonitor.com for
      information purposes, and to assist persons in obtaining information about or
      related to a domain name registration record.  MarkMonitor.com does not guarantee
      its accuracy.  By submitting a WHOIS query, you agree that you will use this Data
      only for lawful purposes and that, under no circumstances will you use this Data to:
       (1) allow, enable, or otherwise support the transmission of mass unsolicited,
           commercial advertising or solicitations via e-mail (spam); or
       (2) enable high volume, automated, electronic processes that apply to
           MarkMonitor.com (or its systems).
      MarkMonitor.com reserves the right to modify these terms at any time.
      By submitting this query, you agree to abide by this policy.

      MarkMonitor is the Global Leader in Online Brand Protection.

      MarkMonitor Domain Management(TM)
      MarkMonitor Brand Protection(TM)
      MarkMonitor AntiPiracy(TM)
      MarkMonitor AntiFraud(TM)
      Professional and Managed Services

      Visit MarkMonitor at http://www.markmonitor.com
      Contact us at +1.8007459229
      In Europe, at +44.02032062220

      For more information on Whois status codes, please visit
       https://www.icann.org/resources/pages/epp-status-codes-2014-06-16-en

    Domain Name: chegg.com
    Registry Domain ID: 20460561_DOMAIN_COM-VRSN
    Registrar WHOIS Server: whois.markmonitor.com
    Registrar URL: http://www.markmonitor.com
    Updated Date: 2017-08-02T04:00:04-0700
    Creation Date: 2000-02-22T16:22:32-0800
    Registrar Registration Expiration Date: 2024-02-22T16:22:32-0800
    Registrar: MarkMonitor, Inc.
      Registrar IANA ID: 292
      Registrar Abuse Contact Email: abusecomplaints@markmonitor.com
      Registrar Abuse Contact Phone: +1.2083895740
      Domain Status: clientUpdateProhibited (https://www.icann.org/epp#clientUpdateProhibited)
      Domain Status: clientTransferProhibited (https://www.icann.org/epp#clientTransferProhibited)
      Domain Status: clientDeleteProhibited (https://www.icann.org/epp#clientDeleteProhibited)
    Registry Registrant ID:
      Registrant Name: Domain Administrator
      Registrant Organization: Chegg Inc.
      Registrant Street: 3990 Freedom Circle,
      Registrant City: Santa Clara
      Registrant State/Province: CA
      Registrant Postal Code: 95054
      Registrant Country: US
      Registrant Phone: +1.4088555700
      Registrant Phone Ext:
      Registrant Fax:
      Registrant Fax Ext:
      Registrant Email: domainrenewals@chegg.com
    Registry Admin ID:
      Admin Name: Domain Administrator
      Admin Organization: Chegg Inc.
      Admin Street: 3990 Freedom Circle,
      Admin City: Santa Clara
      Admin State/Province: CA
      Admin Postal Code: 95054
      Admin Country: US
      Admin Phone: +1.4088555700
      Admin Phone Ext:
      Admin Fax:
      Admin Fax Ext:
      Admin Email: domainrenewals@chegg.com
    Registry Tech ID:
      Tech Name: Domain Administrator
      Tech Organization: Chegg Inc.
      Tech Street: 3990 Freedom Circle,
      Tech City: Santa Clara
      Tech State/Province: CA
      Tech Postal Code: 95054
      Tech Country: US
      Tech Phone: +1.4088555700
      Tech Phone Ext:
      Tech Fax:
      Tech Fax Ext:
      Tech Email: domainrenewals@chegg.com
    Name Server: ns-699.awsdns-23.net
    Name Server: ns-1026.awsdns-00.org
    Name Server: ns-2045.awsdns-63.co.uk
    Name Server: ns-289.awsdns-36.com
    DNSSEC: unsigned
    URL of the ICANN WHOIS Data Problem Reporting System: http://wdprs.internic.net/
    >>> Last update of WHOIS database: 2018-02-13T13:23:33-0800 <<<
    
    whois distro info:
      The Data in MarkMonitor.com's WHOIS database is provided by MarkMonitor.com for
      information purposes, and to assist persons in obtaining information about or
      related to a domain name registration record.  MarkMonitor.com does not guarantee
      its accuracy.  By submitting a WHOIS query, you agree that you will use this Data
      only for lawful purposes and that, under no circumstances will you use this Data to:
       (1) allow, enable, or otherwise support the transmission of mass unsolicited,
           commercial advertising or solicitations via e-mail (spam); or
       (2) enable high volume, automated, electronic processes that apply to
           MarkMonitor.com (or its systems).
      MarkMonitor.com reserves the right to modify these terms at any time.
      By submitting this query, you agree to abide by this policy.

      MarkMonitor is the Global Leader in Online Brand Protection.

      MarkMonitor Domain Management(TM)
      MarkMonitor Brand Protection(TM)
      MarkMonitor AntiPiracy(TM)
      MarkMonitor AntiFraud(TM)
      Professional and Managed Services

      Visit MarkMonitor at http://www.markmonitor.com
      Contact us at +1.8007459229
      In Europe, at +44.02032062220

      For more information on Whois status codes, please visit
      https://www.icann.org/resources/pages/epp-status-codes-2014-06-16-en

  C:\Users\Peter\GitHub_remotes\whois_install>whois -nobanner 50.112.145.222
    Connecting to COM.whois-servers.net...

    WHOIS Server: whois.markmonitor.com
       Registrar URL: http://www.markmonitor.com
       Updated Date: 2016-05-05T23:11:06Z
       Creation Date: 2005-08-18T02:10:45Z
       Registry Expiry Date: 2020-01-16T04:59:59Z
       Registrar: MarkMonitor Inc.
       Registrar IANA ID: 292
       Registrar Abuse Contact Email: abusecomplaints@markmonitor.com
       Registrar Abuse Contact Phone: +1.2083895740
       Domain Status: clientDeleteProhibited https://icann.org/epp#clientDeleteProhibited
       Domain Status: clientTransferProhibited https://icann.org/epp#clientTransferProhibited
       Domain Status: clientUpdateProhibited https://icann.org/epp#clientUpdateProhibited
       Domain Status: serverDeleteProhibited https://icann.org/epp#serverDeleteProhibited
       Domain Status: serverTransferProhibited https://icann.org/epp#serverTransferProhibited
       Domain Status: serverUpdateProhibited https://icann.org/epp#serverUpdateProhibited
       Name Server: R1.AMAZONAWS.COM
       Name Server: R2.AMAZONAWS.COM
       Name Server: U1.AMAZONAWS.COM
       Name Server: U2.AMAZONAWS.COM
       DNSSEC: unsigned
       URL of the ICANN Whois Inaccuracy Complaint Form: https://www.icann.org/wicf/
        >>> Last update of whois database: 2018-02-13T21:36:55Z <<<

    For more information on Whois status codes, please visit https://icann.org/epp

        NOTICE: The expiration date displayed in this record is the date the
        registrar's sponsorship of the domain name registration in the registry is
        currently set to expire. This date does not necessarily reflect the expiration
        date of the domain name registrant's agreement with the sponsoring
        registrar.  Users may consult the sponsoring registrar's Whois database to
        view the registrar's reported date of expiration for this registration.

        TERMS OF USE: You are not authorized to access or query our Whois
        database through the use of electronic processes that are high-volume and
        automated except as reasonably necessary to register domain names or
        modify existing registrations; the Data in VeriSign Global Registry
        Services' ("VeriSign") Whois database is provided by VeriSign for
        information purposes only, and to assist persons in obtaining information
        about or related to a domain name registration record. VeriSign does not
        guarantee its accuracy. By submitting a Whois query, you agree to abide
        by the following terms of use: You agree that you may use this Data only
        for lawful purposes and that under no circumstances will you use this Data
        to: (1) allow, enable, or otherwise support the transmission of mass
        unsolicited, commercial advertising or solicitations via e-mail, telephone,
        or facsimile; or (2) enable high volume, automated, electronic processes
        that apply to VeriSign (or its computer systems). The compilation,
        repackaging, dissemination or other use of this Data is expressly
        prohibited without the prior written consent of VeriSign. You agree not to
        use electronic processes that are automated and high-volume to access or
        query the Whois database except as reasonably necessary to register
        domain names or modify existing registrations. VeriSign reserves the right
        to restrict your access to the Whois database in its sole discretion to ensure
        operational stability.  VeriSign may restrict or terminate your access to the
        Whois database for failure to abide by these terms of use. VeriSign
        reserves the right to modify these terms at any time.

        The Registry database contains ONLY .COM, .NET, .EDU domains and
        Registrars.

    Connecting to whois.markmonitor.com...

    WHOIS Server: whois.markmonitor.com
      Registrar URL: http://www.markmonitor.com
      Updated Date: 2016-05-05T16:11:07-0700
      Creation Date: 2005-08-17T19:10:45-0700
      Registrar Registration Expiration Date: 2020-01-15T00:00:00-0800
      Registrar: MarkMonitor, Inc.
      Registrar IANA ID: 292
      Registrar Abuse Contact Email: abusecomplaints@markmonitor.com
      Registrar Abuse Contact Phone: +1.2083895740
      Domain Status: clientUpdateProhibited (https://www.icann.org/epp#clientUpdateProhibited)
      Domain Status: clientTransferProhibited (https://www.icann.org/epp#clientTransferProhibited)
      Domain Status: clientDeleteProhibited (https://www.icann.org/epp#clientDeleteProhibited)
      Domain Status: serverUpdateProhibited (https://www.icann.org/epp#serverUpdateProhibited)
      Domain Status: serverTransferProhibited (https://www.icann.org/epp#serverTransferProhibited)
      Domain Status: serverDeleteProhibited (https://www.icann.org/epp#serverDeleteProhibited)
    Registry Registrant ID:
    Registrant Name: Legal Department
    Registrant Organization: Amazon.com, Inc.
    Registrant Street: PO BOX 81226
    Registrant City: Seattle
    Registrant State/Province: WA
    Registrant Postal Code: 98108-1226
    Registrant Country: US
    Registrant Phone: +1.2062664064
    Registrant Phone Ext:
    Registrant Fax: +1.2062667010
    Registrant Fax Ext:
    Registrant Email: hostmaster@amazon.com
    Registry Admin ID:
    Admin Name: Legal Department
    Admin Organization: Amazon.com, Inc.
    Admin Street: PO BOX 81226
    Admin City: Seattle
    Admin State/Province: WA
    Admin Postal Code: 98108-1226
    Admin Country: US
    Admin Phone: +1.2062664064
    Admin Phone Ext:
    Admin Fax: +1.2062667010
    Admin Fax Ext:
    Admin Email: hostmaster@amazon.com
    Registry Tech ID:
    Tech Name: Abuse, Amazon Webservices
    Tech Organization: Amazon.com, Inc.
    Tech Street: P.O. Box 81226,
    Tech City: Seattle
    Tech State/Province: Washington
    Tech Postal Code: 98108
    Tech Country: US
    Tech Phone: +1.2062664064
    Tech Phone Ext:
    Tech Fax: +1.2062667010
    Tech Fax Ext:
    Tech Email: abuse@amazonaws.com
    Name Server: u1.amazonaws.com
    Name Server: r2.amazonaws.com
    Name Server: r1.amazonaws.com
    Name Server: u2.amazonaws.com
    DNSSEC: unsigned
    URL of the ICANN WHOIS Data Problem Reporting System: http://wdprs.internic.net/
    >>> Last update of WHOIS database: 2018-02-13T13:32:37-0800 <<<

    The Data in MarkMonitor.com's WHOIS database is provided by MarkMonitor.com for
    information purposes, and to assist persons in obtaining information about or
    related to a domain name registration record.  MarkMonitor.com does not guarantee
    its accuracy.  By submitting a WHOIS query, you agree that you will use this Data
    only for lawful purposes and that, under no circumstances will you use this Data to:
     (1) allow, enable, or otherwise support the transmission of mass unsolicited,
         commercial advertising or solicitations via e-mail (spam); or
     (2) enable high volume, automated, electronic processes that apply to
         MarkMonitor.com (or its systems).
    MarkMonitor.com reserves the right to modify these terms at any time.
    By submitting this query, you agree to abide by this policy.

    MarkMonitor is the Global Leader in Online Brand Protection.

    MarkMonitor Domain Management(TM)
    MarkMonitor Brand Protection(TM)
    MarkMonitor AntiPiracy(TM)
    MarkMonitor AntiFraud(TM)
    Professional and Managed Services

    Visit MarkMonitor at http://www.markmonitor.com
    Contact us at +1.8007459229
    In Europe, at +44.02032062220

    For more information on Whois status codes, please visit
     https://www.icann.org/resources/pages/epp-status-codes-2014-06-16-en
    --


    Domain Name: amazonaws.com
    Registry Domain ID: 197784869_DOMAIN_COM-VRSN
    Registrar WHOIS Server: whois.markmonitor.com
    Registrar URL: http://www.markmonitor.com
    Updated Date: 2016-05-05T16:11:07-0700
    Creation Date: 2005-08-17T19:10:45-0700
    Registrar Registration Expiration Date: 2020-01-15T00:00:00-0800
    Registrar: MarkMonitor, Inc.
    Registrar IANA ID: 292
    Registrar Abuse Contact Email: abusecomplaints@markmonitor.com
    Registrar Abuse Contact Phone: +1.2083895740
    Domain Status: clientUpdateProhibited (https://www.icann.org/epp#clientUpdateProhibited)
    Domain Status: clientTransferProhibited (https://www.icann.org/epp#clientTransferProhibited)
    Domain Status: clientDeleteProhibited (https://www.icann.org/epp#clientDeleteProhibited)
    Domain Status: serverUpdateProhibited (https://www.icann.org/epp#serverUpdateProhibited)
    Domain Status: serverTransferProhibited (https://www.icann.org/epp#serverTransferProhibited)
    Domain Status: serverDeleteProhibited (https://www.icann.org/epp#serverDeleteProhibited)
    Registry Registrant ID:
    Registrant Name: Legal Department
    Registrant Organization: Amazon.com, Inc.
    Registrant Street: PO BOX 81226
    Registrant City: Seattle
    Registrant State/Province: WA
    Registrant Postal Code: 98108-1226
    Registrant Country: US
    Registrant Phone: +1.2062664064
    Registrant Phone Ext:
    Registrant Fax: +1.2062667010
    Registrant Fax Ext:
    Registrant Email: hostmaster@amazon.com
    Registry Admin ID:
    Admin Name: Legal Department
    Admin Organization: Amazon.com, Inc.
    Admin Street: PO BOX 81226
    Admin City: Seattle
    Admin State/Province: WA
    Admin Postal Code: 98108-1226
    Admin Country: US
    Admin Phone: +1.2062664064
    Admin Phone Ext:
    Admin Fax: +1.2062667010
    Admin Fax Ext:
    Admin Email: hostmaster@amazon.com
    Registry Tech ID:
    Tech Name: Abuse, Amazon Webservices
    Tech Organization: Amazon.com, Inc.
    Tech Street: P.O. Box 81226,
    Tech City: Seattle
    Tech State/Province: Washington
    Tech Postal Code: 98108
    Tech Country: US
    Tech Phone: +1.2062664064
    Tech Phone Ext:
    Tech Fax: +1.2062667010
    Tech Fax Ext:
    Tech Email: abuse@amazonaws.com
    Name Server: u1.amazonaws.com
    Name Server: r2.amazonaws.com
    Name Server: r1.amazonaws.com
    Name Server: u2.amazonaws.com
    DNSSEC: unsigned
    URL of the ICANN WHOIS Data Problem Reporting System: http://wdprs.internic.net/
    >>> Last update of WHOIS database: 2018-02-13T13:32:37-0800 <<<

    The Data in MarkMonitor.com's WHOIS database is provided by MarkMonitor.com for
    information purposes, and to assist persons in obtaining information about or
    related to a domain name registration record.  MarkMonitor.com does not guarantee
    its accuracy.  By submitting a WHOIS query, you agree that you will use this Data
    only for lawful purposes and that, under no circumstances will you use this Data to:
     (1) allow, enable, or otherwise support the transmission of mass unsolicited,
         commercial advertising or solicitations via e-mail (spam); or
     (2) enable high volume, automated, electronic processes that apply to
         MarkMonitor.com (or its systems).
    MarkMonitor.com reserves the right to modify these terms at any time.
    By submitting this query, you agree to abide by this policy.

    MarkMonitor is the Global Leader in Online Brand Protection.

    MarkMonitor Domain Management(TM)
    MarkMonitor Brand Protection(TM)
    MarkMonitor AntiPiracy(TM)
    MarkMonitor AntiFraud(TM)
    Professional and Managed Services

    Visit MarkMonitor at http://www.markmonitor.com
    Contact us at +1.8007459229
    In Europe, at +44.02032062220

    For more information on Whois status codes, please visit
     https://www.icann.org/resources/pages/epp-status-codes-2014-06-16-en
    --


</blockquote>