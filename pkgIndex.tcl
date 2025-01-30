# -*- tcl -*-
# Tcl package index file, version 1.1
#
if {[package vsatisfies [package provide Tcl] 9.0-]} {
    package ifneeded libproxy 0.3 \
	    [list load [file join $dir libtcl9libproxy0.3.so] [string totitle libproxy]]
} else {
    package ifneeded libproxy 0.3 \
	    [list load [file join $dir liblibproxy0.3.so] [string totitle libproxy]]
}
