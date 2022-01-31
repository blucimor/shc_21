# install base layer & update OS(debian) (version baster 10)
FROM debian:buster
RUN apt-get update -y
RUN apt-get upgrade -y

# install components Nginx, MariaDB, Wget, php PhpMyAdmin, Wordpress
RUN apt-get install nginx mariadb-server wget php7.3 php-mysql php-fpm -y

# configure Nginx, php, PhpMyAdmin, Wordpress
COPY srcs/config_nginx /etc/nginx/sites-available/default
RUN mkdir /var/www/blucimor
WORKDIR /var/www/blucimor/
COPY . .
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.1/phpMyAdmin-5.0.1-english.tar.gz
RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xvzf phpMyAdmin-5.0.1-english.tar.gz
RUN tar -xvzf latest.tar.gz
RUN rm -rf phpMyAdmin-5.0.1-english.tar.gz
RUN rm -rf latest.tar.gz
RUN mv phpMyAdmin-5.0.1-english phpmyadmin 
RUN mv ./srcs/config.sample.inc.php phpmyadmin/
RUN mv ./srcs/wp-config-sample.php wordpress/

# open ports for HTTP & HTTPS 
EXPOSE 80 443

# rights to files
RUN chown -R www-data /var/www/*
RUN chmod -R 755 /var/www/*

# start server
ENTRYPOINT ./srcs/start.sh
