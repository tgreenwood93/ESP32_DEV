set(COMPONENT_SRCS "cmd_wifi.c"
                   "main.c"
                   "ap.c")
set(COMPONENT_ADD_INCLUDEDIRS ".")

set(COMPONENT_EMBED_TXTFILES
        "certs/cacert.pem"
        "certs/prvtkey.pem")
        
register_component()
project(testDev)
