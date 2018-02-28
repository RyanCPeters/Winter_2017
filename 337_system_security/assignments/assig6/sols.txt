
#### Question #1 from our assignment

Problem
An example of a host-based intrusion detection tool is the tripwire program. This is a file integrity checking tool that scans files and directories on the system on a regular basis and notifies the administrator of any changes. It uses a protected database of cryptographic checksums for each file checked and compares this value with that recomputed on each file as it is scanned. It must be configured with a list of files and directories to check and what changes, if any, are permissible to each. It can allow, for example, log files to have new entries appended, but not for existing entries to be changed. What are the advantages and disadvantages of using such a tool? Consider the problem of determining which files should only change rarely, which files may change more often and how, and which change frequently and hence cannot be checked. Hence consider the amount of work in both the configuration of the program and on the system administrator monitoring the responses generated.

Step-by-step solution
Step 1 of 3
Host based intrusion detection tool:

Host based intrusion detection tool is a checking tool used to scan the files and directories presented on the system and it notifies the changes to the administrator.

• The administrator uses the protected database with cryptographic checksums for each checked file and compares the values with that recomputed scanned file.

• The database is configured with the list of files and directories and it allows the changes of each file

o For example: Appending the new entries in log files but not for the existing entries.

• An example of a host based intrusion detection tool is the “trip wire program”.


Step 2 of 3
While using this tool, there might be some advantages and disadvantages. They are as follows:

Advantages of “trip wire program”:

• The “trip wire program” is useful to recognize the changed files or directories on a system specifically on the files where the change should not have occurred.

• It is less difficult to monitor a small list of configuration files and critical system programs because the changes in that file can be easily detected.

Disadvantages of “trip wire program”:

• Most of the computer systems are not static and the files can change constantly. So, the “trip wire program” has to necessarily configure the files, directories and reports to the administrator with a list of files changed during the normal operation of the system.

• If the large area of the system is not monitored properly, then the changes in the file made by the attacker cannot be detected.

• In the large area of the system, more attention and more care will be needed to identify the files that are not expected to change.

o For example: In home areas of users or other shared document areas cannot be monitored properly because there will be more likely of creating and changing the files.

• Additionally, a special process is needed to manage the update of monitored files.

o This process has to verify whether the files are correct and then it updates the cryptographic checksum of the files.

o Finally, read-only media is required to protect the checksum because it prevents the attempt of corrupting the data by an attacker.


Step 3 of 3
Therefore, the advantages and disadvantages of host based intrusion detection tool is discussed with the given problem consideration.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#### Question #2 from our assignment

Problem
The question arises as to whether it is possible to develop a program that can analyze a piece of software to determine if it is a virus. Consider that we have a program D that is supposed to be able to do that. That is, for any program P, if we run D(P), the result returned is TRUE (P is a virus) or FALSE (P is not a virus). Now consider the following program:

   Program CV:=        {...         main-program:=                  {if D(CV) then goto next:                               else infect-executable;                  }   next:        }
In the preceding program, infect-executable is a module that scans memory for executable programs and replicates itself in those programs. Determine if D can correctly decide whether CV is a virus.

Step-by-step solution
Step 1 of 3
Analyzing the code whether it is a virus infected or not:

, it is possible to develop a program that can examine a part of software to find out if it is a virus.

Comment
Step 2 of 3
Code Explanation:

• The program D checks the CV program and returns TRUE if CV is computer virus and returns FALSE if it is not a virus.

o If D states that the program CV is a virus, then it just goes to next part to process.

• Thus CV will not infect an executable program.

o But, if D states that the program CV is not a virus, then it infects an executable program.

• The given condition in the program is wrong.

Comment
Step 3 of 3
Justification:

The proper way to develop a program that can examine a part of software to find out if it is a virus is as follows,

• If D states that the program CV is a virus, then it infects an executable program.

• If D states that the program CV is not a virus, then it goes to the next part to process.

Therefore, the program D always returns  answer in the given code.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#### Question #3 from our assignment

I didn't find anything for this one yet...

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#### Question #4 from our assignment


Problem
Assume you have found a USB memory stick in your work parking area. What threats might this pose to your work computer should you just plug the memory stick in and examine its contents? In particular, consider whether each of the malware propagation mechanisms we discuss could use such a memory stick for transport. What steps could you take to mitigate these threats, and safely determine the contents of the memory stick?

Step-by-step solution
Step 1 of 2
Threats that are created to the user computer while plug in the memory stick:

• When a memory stick is plugged into the computer which was founded on the parking area may create a variety of threats to the confidentiality, integrity, and availability of the system.

• The memory stick may transmit “executable virus” or “macro virus” on to the system.

o Executable virus - Executable program files are affected by machine executable virus and these program files work with specific operating system and in some cases it is based upon the hardware platform.

o Macro virus - Files with macro or scripting code are affected by macro viruses and its support effective content in a field of user document types and is translated by an application.

• The memory stick may transmit a “malicious worm”.

o Worm - While viewing the memory stick, worm runs automatically and infects other appropriate files as a virus on the system.

• The memory stick may transmit a “Trojan horse”.

o Trojan horse - Trojan horse is the malicious piece of code that is delivered through the mail or web page or through the USB drives that causes damage to the data or system.

Therefore, “executable virus”, “macro virus”, “worm”, and “Trojan horse” are the threats that are created to the user’s computer when a memory stick is plugged in.

Comment
Step 2 of 2
Steps to mitigate the threats:

To mitigate the threats,

• The user should “scan the memory stick” with appropriate up-to-date anti-virus software.

• The user could “check the memory stick” in a controlled environment. For example a live-boot Linux or emulation environment.

Therefore, these are the steps to mitigate the threats.


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#### Question #5 from our assignment


Problem
Suppose you have a new smartphone and are excited about the range of apps available for it. You read about a really interesting new game that is available for your phone. You do a quick Web search for it, and see that a version is available from one of the free marketplaces. When you download and start to install this app, you are asked to approve the access permissions granted to it. You see that it wants permission to “Send SMS messages” and to “Access your address-book”. Should you be suspicious that a game wants these types of permissions? What threat might the app pose to your smartphone, should you grant these permissions and proceed to install it? What types of malware might it be?

Step-by-step solution
Step 1 of 1
The malware called Trojan horse is attacked while the user wants to install a game application.

• If a user wants to download and install game application, the user is asked to agree the access permissions such as “Send SMS messages” and to “Access the address-book”.

o From this type of permission, the user has a doubt whether this permission is needed for a game.

• Relatively, it is a malware that collects details of the user contacts and also return them to the attacker through messages, or permit the code to send messages to the user contacts.

• This could be done by the malware called Trojan horse.

o Trojan horse is the malicious piece of code that is delivered through the mail or web page that causes damage to the data or system.

o It causes loss of data and system damage, so people consider it as a computer virus.

o It may create a variety of threats to the confidentiality, integrity, and availability of the system.

Comment

Was this solution helpful?00

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#### Question #6 from our assignment

Question: 6.14 List the types of attacks on a personal computer that each of a (host-based) personal firewa...
6.14 List the types of attacks on a personal computer that each of a (host-based) personal firewall, and anti-virus software, can help you protect against.

Which of these countermeasures would help block the spread of macro viruses spread using email attachments?

Which would block the use of backdoors on the system?

Textbook:

Computer Security
Principles and Practice
Third Edition
William Stallings
Lawrie Brown

Expert Answer
Anonymous
Anonymous answered this Was this answer helpful?
0
1
13 answers
The answer to this question is a resounding yes. To meet minimum security requirements, you need to run both antivirus and firewall on your computer.
Antivirus and firewall have very different - and necessary - functions. Antivirus software detects and removes viruses, Trojan horses, worms, bots and other malware from your computer. Good free antivirus firewall software, like ZoneAlarm Free Antivirus + Firewall, will also protect your computer from spyware and adware. The main function of antivirus software is to scan your computer for malware infections and then treat any that it finds. For more information on antivirus software and what to expect, click here.
Firewall prevents malware and other Internet hacker attacks from reaching your computer in the first place. It's your computer's first line of defense. A firewall creates a filter between your computer and the Internet. Before anything can go through this barrier, the firewall must determine whether the information meets your computer's security settings. If this traffic fails to meet these security rules, the firewall will deny it access to your computer. If you download a two-way firewall, such as ZoneAlarm Free Firewall, the firewall protection will also prevent any suspicious traffic - like spyware that is trying to send your personal information out to the Internet - from leaving your computer.
Because antivirus and firewall serve different roles, they work together to provide your computer with the best protection possible. We recommend ZoneAlarm Free Antivirus + Firewall because these two solutions are specifically designed to complement each other - and you get the best antivirus and firewall protection absolutely free


Security Attacks

This page lists types of security attacks. This document will address security issues, measures, and policies which take these types of attacks into consideration.

DoS- Denial of Service
Trojan Horse - Comes with other software.
Virus - Reproduces itself by attaching to other executable files.
Worm - Self-reproducing program. Creates copies of itself. Worms that spread using e-mail address books are often called viruses.
Logic Bomb - Dormant until an event triggers it (Date, user action, random trigger, etc.).
Hacker Attacks

I use the term "hacker attacks" to indicate hacker attacks that are not automated by programs such as viruses, worms, or trojan horse programs. There are various forms that exploit weakneses in security. Many of these may cause loss of service or system crashes.

IP spoofing - An attacker may fake their IP address so the receiver thinks it is sent from a location that it is not actually from. There are various forms and results to this attack.
The attack may be directed to a specific computer addressed as though it is from that same computer. This may make the computer think that it is talking to itself. This may cause some operating systems such as Windows to crash or lock up.
Gaining access through source routing. Hackers may be able to break through other friendly but less secure networks and get access to your network using this method.
Man in the middle attack -
Session hijacking - An attacker may watch a session open on a network. Once authentication is complete, they may attack the client computer to disable it, and use IP spoofing to claim to be the client who was just authenticated and steal the session. This attack can be prevented if the two legitimate systems share a secret which is checked periodically during the session.
Server spoofing - A C2MYAZZ utility can be run on Windows 95 stations to request LANMAN (in the clear) authentication from the client. The attacker will run this utility while acting like the server while the user attempts to login. If the client is tricked into sending LANMAN authentication, the attacker can read their username and password from the network packets sent.
DNS poisoning - This is an attack where DNS information is falsified. This attack can succeed under the right conditions, but may not be real practical as an attack form. The attacker will send incorrect DNS information which can cause traffic to be diverted. The DNS information can be falsified since name servers do not verify the source of a DNS reply. When a DNS request is sent, an attacker can send a false DNS reply with additional bogus information which the requesting DNS server may cache. This attack can be used to divert users from a correct webserver such as a bank and capture information from customers when they attempt to logon.
Password cracking - Used to get the password of a user or administrator on a network and gain unauthorized access.
Some DoS Attacks

Ping broadcast - A ping request packet is sent to a broadcast network address where there are many hosts. The source address is shown in the packet to be the IP address of the computer to be attacked. If the router to the network passes the ping broadcast, all computers on the network will respond with a ping reply to the sttacked system. The attacked system will be flooded with ping responses which will cause it to be unable to operate on the network for some time, and may even cause it to lock up. The attacked computer may be on someone else's network. One countermeasure to this attack is to block incoming traffic that is sent to a broadcast address.
Ping of death - An oversized ICMP datagram can crash IP devices that were made before 1996.
Smurf - An attack where a ping request is sent to a broadcast network address with the sending address spoofed so many ping replies will come back to the victim and overload the ability of the victim to process the replies.
Teardrop - a normal packet is sent. A second packet is sent which has a fragmentation offset claiming to be inside the first fragment. This second fragment is too small to even extend outside the first fragment. This may cause an unexpected error condition to occur on the victim host which can cause a buffer overflow and possible system crash on many operating systems.

Protecting your Email from Viruses and Other MalWares-

How Email Viruses Work

There are a couple of different ways that viruses can invade your computer through your email box. One of the most publicized is through attachments. If you open an executable file that’s attached to a mail message, the program runs and the virus does its dirty work – in some cases not only doing damage on your own machine but also using your address book to mail copies of itself to everyone with whom you correspond. These infected messages will appear to be from you, even though you weren’t even aware that they were sent. That’s why you should always be wary of mail with attachments, even when it comes from someone you know and trust. Viruses that work this way include the infamous Melissa virus, Klez, and others.

Avoiding attachment viruses would seem to be easy: just don’t open attachments. However, it’s not always that simple. Many of us whose work depends on collaborating with others across the Internet need to exchange attachments. If you do, common sense precautions should prevail. Note the file type before opening an attachment. Executables are most likely to be dangerous, but virus writers use tricks such as appending multiple file extensions to fool you into thinking a file is something it’s not. Because the Windows Explorer and some software programs don’t show common extensions by default, a file named letter.txt.exe will appear to be an innocuous text file when it’s really a program file.

Because the problem of viruses in attachments is so prevalent, Microsoft has written recent versions of Outlook (2002 and above) to automatically block executable file types (.exe, .bat, .com, .lnk, .scr, .vbs and many others). This feature is also added to Outlook 2000 when you apply Service Pack 2 or to Outlook 98 when you apply the Outlook Email Security Update. Unfortunately, this creates a situation where the cure may be worse than the disease if you really need to send and receive those types of files. If so, there are several ways to work around this problem.

The simplest method is to just rename the file with a different extension (for example, rename program.exe to program.txt) and tell the person to whom you’re sending it to rename it to the original name after downloading it.

In Outlook 2002, you can edit the Registry to modify the file types that are blocked. There are several third-party utilities that will let you do the same thing without directly editing the Registry; these include Outlook Permissions Add-in from MRH Technolgoy Group, DetachXP from McDaniel Development and the Xenos Outlook Security Extension.

Note that attachment blocking is optional in Outlook Express, and Outlook Web Access does not include attachment blocking. So another way to get your attachments is to use OWA (if you’re in an Exchange environment) or import your messages into OE from Outlook.

Don’t assume that you’re okay if the only attachments you open are document files. Word documents can contain macros (small programs) that can execute malicious commands. These are called macro viruses. You can protect yourself by setting the Macro Security level in Word (accessed via Tools | Options | Security tab) to medium or high. High disables all unsigned macros, and medium prompts you before running a macro, as shown in Figure A.

Figure A: Set Macro Security in Word to medium or high to protect from macro viruses

You can’t assume your mail is safe just because you don’t get attachments, either. Viruses can also be embedded in the mail message itself. This isn’t possible in a plain text message, but the most popular mail clients today (Outlook, OE, Eudora) support HTML mail so you can use stationery, embed pictures and sound, and so forth. An HTML message can contain scripts (programs) that execute viruses. This is one reason many mailing lists block HTML mail (another is bandwidth usage).

The latest version of Outlook (2003), now in beta testing, finally allows users to block HTML mail. This is a continuation of a trend that started in Outlook 2002 (XP), when Microsoft started blocking external content (files grabbed from outside servers) in the preview pane. To convert incoming HTML to plain text in Outlook 2000, you can use VBA code. In Outlook 2002, you can use the Rules Wizard’s “run a script” action to call a VBA subroutine to perform this conversion (instructions for both of these methods may be found here).

Rich text can also be exploited to send unauthorized messages, and even plain text messages can contain URLs that may take you to web sites where scripts run and disseminate viruses.

Protective Measures you can Take

Most viruses are operating system specific (that is, viruses that run on Windows often don’t affect Linux or Macintosh computers, and vice versa) and many are also specific to certain email clients. The first step in protecting your computer from email viruses is to apply all service packs and security updates, both those for your OS and those for your email software. Because the mail client may interact with the browser when reading HTML mail, you should also apply the latest updates to Internet Explorer.

Your mail client should be configured so that ActiveX and Java scripts won’t run automatically. In Outlook and OE, this is done through the settings for the Restricted Sites security zone (Tools | Options | Security). Choose Custom Level and scroll through the list of options, and set the option button for each ActiveX or scripting setting to either “disable” or “prompt,” as shown in Figure B.

Figure B: Disabling ActiveX and scripting in Outlook (or requiring a prompt) will prevent these components from executing automatically

If you use Eudora, in Tools | Options | Viewing Mail, you should disable “allow executables in HTML content.” For Netscape Mail, in Edit | Preferences, Advanced Category, uncheck “enable Javascript for Mail and News.”

The next step is to install a good anti-virus or email security program. Although an AV program will help, it may not be enough to protect a mission-critical network. In that case, a more comprehensive “email firewall” such as GFi MailSecurity for Exchange can check mail content as well as checking for viruses. Remember that new viruses are being created daily, so any virus software will need to have its definition files updated regularly.

Summary

How vulnerable is your network to email viruses and attacks? You can visit the Email Security Testing Zone at GFI’s web site to find out. Email is truly the “killer app” of the 21st century – businesses and individuals depend on electronic mail for quick, easy, reliable communication. However, your email system is a point of vulnerability that can exploited to invade your system and network. Viruses can destroy data, damage system files that are necessary to run your operating system and applications, and even bring down the entire network through denial of service attacks. If this weren’t enough, these viruses can use your address books to spread themselves further. If you use email, you need to take steps to ensure that you’re protected against viruses, Trojans and other malicious software that can be transmitted via email – without compromising the email features you need to communicate effectively. In this article, we’ve provided an overview of email security issues and pointers to solutions that may be right for your computer and network.


back door definition

A back door is a means of access to a computer program that bypasses security mechanisms. A programmer may sometimes install a back door so that the program can be accessed for troubleshooting or other purposes. However, attackers often use back doors that they detect or install themselves, as part of an exploit. In some cases, a worm is designed to take advantage of a back door created by an earlier attack. For example, Nimda gained entrance through a back door left by Code Red.Whether installed as an administrative tool or a means of attack, a back door is a security risk, because there are always crackers out there looking for any vulnerability to exploit. In her article "Who gets your trust?" security consultant Carole Fennelly uses an analogy to illustrate the situation: "Think of approaching a building with an elaborate security system that does bio scans, background checks, the works. Someone who doesn't have time to go through all that might just rig up a back exit so they can step out for a smoke -- and then hope no one finds out about it
