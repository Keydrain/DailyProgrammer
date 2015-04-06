#!/usr/bin/Perl

=for comment
Solution for Easy Challenge #010
Author: Keydrain
Date: 04/04/15
=cut

use strict;
use warnings;
use diagnostics;

print "\nPlease enter your phone number: ";
my $num = <>;

chomp($num);

if ($num =~ /(\d{9})/ or 
	$num =~ /(\d{3}\-\d{3}\-\d{4})/ or 
	$num =~ /(\d{3}\.\d{3}\.\d{4})/ or 
	$num =~ /(\(\d{3}\)[ ]*\d{3}\-\d{4})/ or 
	$num =~ /(\d{3}\-\d{4})/) {
	print "$num is a valid phone number.\n\n";
} else {
	print "$num is not a valid phone number.\n\n";
}