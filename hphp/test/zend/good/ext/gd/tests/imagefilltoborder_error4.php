<?php
// Create a image 
$image = imagecreatetruecolor( 100, 100 ); 

// Draw a rectangle
imagefilledrectangle( $image, 0, 0, 100, 100, imagecolorallocate( $image, 255, 255, 255 ) );

// Draw an ellipse to fill with a black border
imageellipse( $image, 50, 50, 50, 50, imagecolorallocate( $image, 0, 0, 0 ) );

// Try to fill border
imagefilltoborder( $image, 50, 50, 'wrong param', imagecolorallocate( $image, 255, 0, 0 ) );

?> 
