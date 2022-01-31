<?php
// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'blucimor' );

/** MySQL database password */
define( 'DB_PASSWORD', 'qwerty' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',         '^wH+hA%O=t|l||TQUL3nG74e[JFln!1:va4* .Fi4-c+C[[WKhMq?`#PG?n74|8i' );
define( 'SECURE_AUTH_KEY',  '-l_z9;VqxAOb!?RCT%is,+SuwGHV>c Jzjw-S9Z@s5!3MIJ}rQMo.f%]U!ojAC|(' );
define( 'LOGGED_IN_KEY',    'WW(X oC AQca*(.>>#E7Ab[fYVb7U{v09a4s>Yej,Y17#berHxCUxiEe|mS198A`' );
define( 'NONCE_KEY',        'peq(I%X;P6.6g.S|8w?]8X9=jGnAvxFvjROqOy>+e(}4I+9}rTor09;?]wFGx/f#' );
define( 'AUTH_SALT',        '3Tb9?^A~N,0brDtfo7d|3+{zV:HNF>*5-|ee0+gqeoWl^?TCk-mg]ia-aUea^6?Q' );
define( 'SECURE_AUTH_SALT', '4y(6!&D||-}tZ_O<)C[X-{w_`j|O^Mb ;,o-B!~PdMj:es&ZQkB6YRz5p^dn7^/e' );
define( 'LOGGED_IN_SALT',   'V ]p:Qn0]Q5VQ&Lt)WJRqy@K[MzO|pjc!0Upd_PW!F}a%oG@g.b|A4 $0:M%^<?.' );
define( 'NONCE_SALT',       ':)<zM+sg]m$[09((R>k8irG;IYx~N1O|xJ*`>|MCe8?Iz-VNFmw^s(:Q&#ZJs(=b' );


/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
        define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';