Nginx Static Etags
------------------

Nginx doesn't generate etags for static content.  I think it should.  If I can remember enough C from college to make it work as a module, I will.

### Installation

Download the module however you like.  I'd recommend pulling it down with Git by simply cloning this repository:

    mkdir ~/src
    cd    ~/src
    git clone git://github.com/mikewest/nginx-static-etags.git ./nginx-static-etags

To use the module, you'll have to compile it into Nginx.  So, download the Nginx source, configure it with the module path, and compile:

    mkdir ~/src
    cd ~/src
    curl -O http://sysoev.ru/nginx/nginx-0.6.32.tar.gz
    tar -zxvf ./nginx-0.6.32.tar.gz
    cd ./nginx-0.6.32
    ./configure --add-module=/Users/mikewest/Repositories/nginx-static-etags
    make
    sudo make install
    
And you're done!

### Configuration

Add `FileEtag` to the relevant `location` blocks in your `nginx.conf` file:

    location / {
        ...
        FileETag on;
        ...
    }

It's currently an on/off toggle.  The plan is to bring it to feature parity with [the Apache configuration option][apache].  It's really not there yet.

[apache]: http://httpd.apache.org/docs/1.3/mod/core.html#fileetag