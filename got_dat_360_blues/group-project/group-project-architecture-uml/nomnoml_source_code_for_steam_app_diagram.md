#title: Steam App diagram 
#font: Consolas
#.package: fill=#4b2e83
#.source: fill=#222
#.domain: fill=#203030
#fill: #4b2e83
#.feature: fill=#4b2e83
#stroke: #85754d 
#.subpackage:
#edgeMargin: 1
#fontSize:12
#spacing: 90
#padding: 10
#gutter: 10
#direction: down 

[<source> Group: Sparkle Motion; Steam Stream Architecture Diagram|
  [<package> Systems Architecture|
  
    [<domain> <<interface>> Steam Application]
    
    [<domain> <<service>> Workshop|
      Custom Overlays
      Custom Skins
    ]
    
    [<domain> <<service>> Steam Store Marketplace|
      Game Specific Market Pages
    ]
    #end Steam Store Marketplace service:
    
    [<domain> <<service>> Steam Stream|
      Stateful|
      [<feature>Clip Process|
        stateful|
        ioformatter(): tar or zip (user defined)
      ]
      [<feature>Video Process|
        stateful|
        feed_synch(): ioByteBuffer]
      [<feature>Stream Process|
        stateless|
        quantization(): byte stream
      ]
      #The_following_choice_blocks_are_based_upon_pre-selected_user_preferences:
      [<choice>make clip?]
      [<choice>stream clip?]
      #Define decision logic relationships:
      [<start>user input] input -> [<>Video Process]
      [<>Stream Process] -> [<end> return to user]
      [<>Clip Process] -> [<>stream clip?]
      [<>stream clip?] -> yes[<>Stream Process]
      [<>Video Process] -> [<> make clip?]
      [<> make clip?] -> no [<> Stream Process]
      [<> make clip?] -> yes [<> Clip Process ]
      [<>stream clip?] no -> output [<end> return to user]
    ]
    #end Steam stream service:
    
    [<domain> <<interface>> API For Third Party Services|
      YouTube Gaming suite 
        Twitch Streaming suite
        Mixer Streaming suite
    ]
    #end API for Third Party Services:
    
    #define top level architecture relations:
    [<actor>Zombie Gamer]--:>[<><<interface>> Steam Application]
    [<><<interface>> Steam Application] packaged output feeds <-> User video feed[<><<service>> Steam Stream]
    [<><<interface>> Steam Application]<:--:> *slight hand waving* [<><<interface>> API For Third Party Services]
    [<><<interface>> Steam Application]<->[<><<service>> Workshop]
    [<><<interface>> Steam Application]<->[<><<service>> Steam Store Marketplace]
    
  ]
]
