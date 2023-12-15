# -*- tcl -*-
# Tcl package index file, version 1.1
#
if {[package vsatisfies [package provide Tcl] 9.0-]} {
    package ifneeded libproxy 0.1 \
	    [list load [file join $dir libtcl9libproxy0.1.so] [string totitle libproxy]]
} else {
    package ifneeded libproxy 0.1 \
	    [list load [file join $dir liblibproxy0.1.so] [string totitle libproxy]]
}
