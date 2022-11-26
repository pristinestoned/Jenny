J-Alice is an Alicebot written in C++. It is an advanced AI chatbot with a powerful matching engine. It also features an irc mode, http server mode and a few other ways of interacting with people.

J-Alice should compile *out of the box* on Linux, BeOS, Solaris, Windows, FreeBSD and MacOSX .. hopefully on other BSDs as well.

HELP WANTED: 
autoconf support
web designer
logo
coders
documentation writers
and people with cool ideas to push j-alice further into the "whoa!" realm

Miscellaneous Stuff:


How to configure built-in services
----------------------------------

You need to edit the j-alice.ini file.

This is a new configuration format we are trialling .. it is yet to change.

A lot of the options don't actually work as yet, just the core components to get
it running.

For new IRC Networks, just copy the OpenProjects.Net config, and alter the
important values (eg: port, server, channels, nicks, etc).

The PassThru Port value is the port that a builtin IRC Server will listen on.

The only working services at the moment are:

- IRC Clients

- Web Server

The other services do not work. This means that the XML Socket Server most likely
won't run. I haven't tested it myself, but I am quite sure that I have disabled
that.

Where is the interaction in console/terminal?
---------------------------------------------

It's gone. Later, it _may_ come back to linux platforms.

Due to our non-threaded application, and the Socket API we have designed, it is
rather difficult to have console & sockets both functional, though, apparently
console can use our Socket API for linux platforms.

Do not expect console support to come back in the future. And no, we do not have
an option to disable sockets and use only console.

All the console is used for is to show debug messages and other possibly useful
information, such as the matched categories, IRC disconnection/reconnection
messages, etc.

Shutting down the bot
---------------------

Please use the provided category: SHUTDOWN SERVER

This will tell the bot to cease all activity, save any data, and quit. It won't
always be instantaneous, and may take a few seconds to complete.

If you DO NOT SHUTDOWN THE BOT PROPERLY: you will lose all user predicates that
are set using <set/> and possibly some other data. At present, the bot does not
save all new/changed predicates to disk except at shutdown.

Using CTRL+C to kill the bot is not a proper shutdown. Nor is clicking the close
button on the terminal/console window. If any of these are done, predicates will
not be saved.

It is also recommended to use <secure/> to stop people shutting down the bot. It is
not secure by default, so you will need to edit it. You will also have to provide a
category to authorise yourself.

Please put those changes in the std-startup.aiml file.

For shutting down the bot, it may be easiest to do the following:

1) Open Internet Explorer (or other browser)
2) Go to: http://localhost:<port>
   <port> is the value set in j-alice.ini under the web server section
3) Type: shutdown server

J-Alice should then shutdown .. it may not happen instantly, but it should work.

Secure/Authentication Examples
------------------------------

<template>
<!-- beginning of template processed regardless of who you are -->
<secure error="An error message if not authenticated">
<!-- contents processed if authenticated -->
</secure>
<!-- remaining template processed regardless of who you are -->
</template>

<Category>
<pattern>LOGIN</pattern>
<template>
<think><set name="context">login</set></think>
Please enter the password
</template>
</category>

<category>
<pattern>YES</pattern>
<that>TRY LOGGING IN AGAIN</that>
<template><srai>LOGIN</srai></template>
</category>

<context name="LOGIN">

<category>
<pattern>*</pattern>
<that>PLEASE ENTER THE PASSWORD</that>
<template>
You have entered an incorrect password. Try logging in again?
<think><set name="context">*</set></think>
</template>
</category>

<category>
<pattern>MY PASSWORD</pattern>
<that>PLEASE ENTER THE PASSWORD</that>
<template>
<think>
<authenticate/>
<set name="context">*</set>
</think>
You are now authorised to use secure content
</template>
</category>

</context>

Obtaining Help
--------------

We have forums & mailing list available for help.

All are available through our website:
http://j-alice.org

The Open Discussion Forum is for comments/suggestions, AIML ideas, etc.
The Help Forum is for problems configuring/running J-Alice, etc.

The Mailing List is open for various topics J-Alice related. For help, consider
using the Help Forum first.

The Forums may not always show your post straight away. SourceForge isn't quick
as lightning, but it will get there. Alternatively, if you have a SourceForge account, you may want to try their NNTP service for reading & posting to the forums. There are more docs on their website.
