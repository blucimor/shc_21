#!/bin/bash
service mysql start
echo "CREATE DATABASE wordpress;" | mysql
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'blucimor'@'localhost' IDENTIFIED by 'qwerty';" | mysql
echo "FLUSH PRIVILEGES;" | mysql
service php7.3-fpm start
openssl req -x509 -days 30 -nodes -subj "/C=RU/ST=Russia/L=Moscow/O=Ecole42/OU=21 School/CN=blucimor" \
-newkey rsa:2048 -keyout /etc/ssl/blucimor-ssl-key.key -out /etc/ssl/blucimor-ssl-crt.crt;
service nginx start
bash