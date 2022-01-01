#include <pgmspace.h>

#define SECRET
#define THINGNAME "openmqtt"

const char WIFI_SSID[] = "mywifi";
const char WIFI_PASSWORD[] = "abc1234";
const char AWS_IOT_ENDPOINT[] = "a1jx3xyqljdro6-ats.iot.us-east-2.amazonaws.com";

// Amazon Root CA 1
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)EOF";

// Device Certificate
static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWjCCAkKgAwIBAgIVALRGC/GAp+ubHPMmszvhaA8uaacuMA0GCSqGSIb3DQEB
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yMTEwMDExMTE5
MTVaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDHX72V9V9NTEqGsuBP
xHqMPIjL04QZosNw0popIh+Fooj1A9Kh0JiSMsWQrApUiRWAm6qbA6fTREq7J5VA
k/6DWQuRNZU8tjUr2WFxgmnZbNqHrOvWNGD4ArMZ6al2TjqY3bnSh/hXDA61KojK
YS40XQHZFoIzl/hU/s6ySSMAcPF8rBSSKPv4c9OJrpShiWO4s5N08ao2JMDEAzP6
Y3cjoPenhs2z7h5lUEx+uccWIFHJyxJwstXbc7J7jKgNROi6DCnWORDiSkZ2zpSK
xYyH5eAvfuPBaJ2QZbYJ176JJGVQ/bFD8rX9Qt/TIS906K9jGFtC4SMIjSC41jmk
bOyfAgMBAAGjYDBeMB8GA1UdIwQYMBaAFCuHowVLRfVozC5gMoy/9DTaXz61MB0G
A1UdDgQWBBQ+oIbp37H08fz7Ac4iDwuVVkFk+jAMBgNVHRMBAf8EAjAAMA4GA1Ud
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEAZBDj+RD3X6vHRV3tSVASs6SF
E/C7Wvjrp4HXKX9dDqcm8uwCFcmll90R6TVdac11uJMik+8NUGZPQWCENX8h4MLl
CxzFJX/X26wAN+tH/QSFcQmKB8vpk4vV2YoBe0MYF8GJf7K5o406IkSKDgMxxAqy
h1dkUWnvGUYkq0J/JoFIHEMCu4GG+zRoWpNF4UXT3zt1xCVxRvgtzOhe7Nnhh1cU
4zsUv88JN6WaDwCOGJDii+FyVxIf6voIuMwPvz91TfMOQzVaChhb4dOYgFO1Mfdg
HdXM+YDqsBs958QR8TC9ls1P2RyQRL+KiSsGXW3O/5hYudYE1SsYvEORLj/KjQ==
-----END CERTIFICATE-----
)KEY";

// Device Private Key
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEpAIBAAKCAQEAx1+9lfVfTUxKhrLgT8R6jDyIy9OEGaLDcNKaKSIfhaKI9QPS
odCYkjLFkKwKVIkVgJuqmwOn00RKuyeVQJP+g1kLkTWVPLY1K9lhcYJp2Wzah6zr
1jRg+AKzGempdk46mN250of4VwwOtSqIymEuNF0B2RaCM5f4VP7OskkjAHDxfKwU
kij7+HPTia6UoYljuLOTdPGqNiTAxAMz+mN3I6D3p4bNs+4eZVBMfrnHFiBRycsS
cLLV23Oye4yoDUTougwp1jkQ4kpGds6UisWMh+XgL37jwWidkGW2Cde+iSRlUP2x
Q/K1/ULf0yEvdOivYxhbQuEjCI0guNY5pGzsnwIDAQABAoIBAGLHZpDjjyInCE2Q
Vl5vBCBy5XvHAg4JfDdrwIFcrK1zB9QM3tDZHp5glU3GTx/vAz5C4dYHi6C6lyP+
yo3CRTkiZv68w4He7J0bCJJKgNL+gY7y962bKef2vnG6OQGqZJHUWPqb70iBatAL
kNZkK5Y59m5uHngddSX3UMU4QyU18C8YGhw903twQ68TLszJu3IlCf1twCnPd9LE
RbtguCH45A0zigTD2xYRbUFbRZEX9um+g6yYd49g8Yi4p6zLV6tk0FCGK2O1pUWN
+LMdHlUehMA9D2lM76MtFJxSY17EBFmh5Bd3IbZFsYCYMIHXwfpX+9DZ5S+yW2HX
VURs9qECgYEA5CBaDEJ4p3pHl5q3Z69mVNj3XHcNyJ+4wkXWhAbUxeAA6KTzKXdd
uALDGwQBUIPpXhkTpccEH9HhUfAMfx06zqVmTGzsjO5Jg+yexDZSCYPRsUaOOIyh
vpY1K/TbVnwDd4L5x50lA7FUnCzWJ6vY0473xEeZjSf6t7Fm7XTFNwcCgYEA37wI
SjhyWL2IP+mM1Z7kMAkvv7M6lD89w5iV/BmKN9OFBADEPvQoE85zXrZ2fyVyqrNe
v2AG8ygsnc7MdcgK8yB8dZjucRxgr+hosDuN6ZZnJE6+DhI5vIXABItJ1OxJsnyd
7MNVrIOpM0+t//7clM6TvsI3T+qCdbyfsqawX6kCgYEAipdY/Y+4i07PhbwZ5mT6
D1wM02EEv7jBX01caLNZuqk/BBeKHswE5NDQxW3meorZUTB87j79M3OnpsbmYKda
XcbAYnfeMjRl9z7eqaeyqVMrJr8Nki9l6EqLHRxR0LXgyU+J/gprPVYTaBoZNNrD
DKwTvGwfTlFWkRi2xlYlpisCgYAMqzoQ8ddPvRO9Ar2Nzxx+t9ZzVXPItzgJHlfH
2a5g8OJEUsLKCctHK9aOk2hsVLOEhPmlfouGM00rdm1Pcg9kqv9BLXK7Bu9WpqNe
71Be3Lxkau0KIPASA8TWvQhmPScDK1lJ8dmlFiN7m1Rv/X+CEZx+HcNCDDZs8kxc
smGkWQKBgQCGMZsHaSxwDW+j7wb5g3rQtetMA06snPMl3v1ELo5v5D41t7dNQF6i
UX9W+G6kBdg5KDiJWStFkiXnTcbOkllUE0EJlb769xk+Mif+sQ5MCFy0ZYKCJOQi
NNnirugKDtCoG1I7BU4JY58DN6RQu+xjrtXZfg/7CB6AgWbA/+CLKg==
-----END RSA PRIVATE KEY-----
)KEY";
