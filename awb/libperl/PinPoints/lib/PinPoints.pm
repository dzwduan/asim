#
# Copyright (C) 2003-2006 Intel Corporation
# 
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
# 
#

## -*-Perl-*-

## Taken from ISpike:  ppload.pm,v 1.1 2003/07/29 01:57:04 mcadler
##
## Load a pinpoints file generated by ppgen.  The LoadPPFile() function
## returns a messy data structure.  Callers don't need to look inside it.
## The accessor functions return all components.
##
## See the DumpPPData() subroutine to see how all fields are accessed.
##

use strict;
package PinPoints;

our $VERSION = "0.1";

##
## Global properties
##

sub TotalDynamicIcount # ( \ %pp )
{
    my $pp = shift;

    if (defined($pp->{'totalIcount'})) {
        return $pp->{'totalIcount'};
    }
    else {
        return 0;
    }
}

##
## Region access functions.
##

sub NRegions # ( \%pp )
{
    my $pp = shift;

    return 0 if (! defined($pp) || ! defined($pp->{'region'}));

    my $nr = $#{$pp->{'region'}};
    return ($nr < 0 ? 0 : $nr);
}

sub GetRegion # ( \%pp, $regionNum )
{
    my $pp = shift;
    my $regionNum = shift;

    return \%{$pp->{'region'}[$regionNum]};
}

sub GetRegionWeight # ( \%region )
{
    my $region = shift;

    return $region->{'weight'};
}

sub GetRegionLength # ( \%region )
{
    my $region = shift;

    return $region->{'length'};
}

sub GetRegionInstrOffset # ( \%region )
{
    my $region = shift;

    return $region->{'offset'};
}


##
## Start and end point access functions
##

sub NStartPoints # ( \%region )
{
    my $region = shift;

    return 0 if (! defined($region) || ! defined($region->{'start'}));

    my $ns = $#{$region->{'start'}};
    return ($ns < 0 ? 0 : $ns);
}

sub GetStartPoint # ( \%region, $startNum )
{
    my $region = shift;
    my $startNum = shift;

    return \%{$region->{'start'}[$startNum]};
}

sub NEndPoints # ( \%region )
{
    my $region = shift;

    return 0 if (! defined($region) || ! defined($region->{'end'}));

    my $ne = $#{$region->{'end'}};
    return ($ne < 0 ? 0 : $ne);
}

sub GetEndPoint # ( \%region, $endNum )
{
    my $region = shift;
    my $endNum = shift;

    return \%{$region->{'end'}[$endNum]};
}

sub GetPointMarkId # ( \%point )
{
    my $point = shift;

    return $point->{'mark'};
}

sub GetPointMarkAddr # ( \%pp, \%point )
{
    my $pp = shift;
    my $point = shift;

    my $mark = GetMark($pp, GetPointMarkId($point));
    return GetMarkAddr($mark);
}

sub GetPointExeCount # ( \%point )
{
    my $point = shift;

    return $point->{'ecount'};
}

sub GetPointInstrOffset # ( \%point )
{
    my $point = shift;

    return $point->{'offset'};
}


##
## Marker instruction access functions
##

sub NMarkedInstrs # ( \%pp )
{
    my $pp = shift;

    return 0 if (! defined($pp) || ! defined($pp->{'mark'}));

    my $nm = $#{$pp->{'mark'}};
    return ($nm < 0 ? 0 : $nm);
}

sub GetMark # ( \%pp, $markNum )
{
    my $pp = shift;
    my $markNum = shift;

    return \%{$pp->{'mark'}[$markNum]};
}

sub GetMarkAddr # ( \%mark )
{
    my $mark = shift;

    return $mark->{'addr'};
}

sub MarkIsInStart # ( \%mark )
{
    my $mark = shift;

    return $mark->{'inStart'};
}

sub MarkIsInEnd # ( \%mark )
{
    my $mark = shift;

    return $mark->{'inEnd'};
}

sub MarkIsNOP # ( \%mark )
{
    my $mark = shift;

    return $mark->{'isNop'};
}


##
## Load a pinpoints file and store the loaded data in the supplied variable.
## Call like this:
##
##    my %pp;
##    LoadPPFile("ppfilename", \%pp);
##

sub LoadPPFile # ( $fileName, \%pp )
{
    my $fileName = shift;
    my $pp = shift;
    my @fields;
    my $line = 0;
    my $curRegion = 0;

    undef %$pp;

    open(PPF, $fileName) or die "Failed to open pinpoint file $fileName";
    while (<PPF>) {
        $line += 1;
        chomp $_;

        if (/^region /) {
            @fields = split(/  */, $_);
            die "Illegal region entry, line $line" if ($#fields != 6);
            $curRegion = $fields[1];
            $pp->{'region'}[$curRegion]{'weight'} = $fields[2];
            $pp->{'region'}[$curRegion]{'length'} = $fields[5];
            $pp->{'region'}[$curRegion]{'offset'} = $fields[6];
        }

        if (/^start /) {
            @fields = split(/  */, $_);
            die "Illegal start entry, line $line" if ($#fields != 3);
            my $n = 0;
            if (defined($pp->{'region'}[$curRegion]{'start'}[0])) {
                $n = $#{$pp->{'region'}[$curRegion]{'start'}} + 1;
            }
            $pp->{'region'}[$curRegion]{'start'}[$n]{'mark'} = $fields[1];
            $pp->{'region'}[$curRegion]{'start'}[$n]{'ecount'} = $fields[2];
            $pp->{'region'}[$curRegion]{'start'}[$n]{'offset'} = $fields[3];
        }

        if (/^end /) {
            @fields = split(/  */, $_);
            die "Illegal end entry, line $line" if ($#fields != 3);
            my $n = 0;
            if (defined($pp->{'region'}[$curRegion]{'end'}[0])) {
                $n = $#{$pp->{'region'}[$curRegion]{'end'}} + 1;
            }
            $pp->{'region'}[$curRegion]{'end'}[$n]{'mark'} = $fields[1];
            $pp->{'region'}[$curRegion]{'end'}[$n]{'ecount'} = $fields[2];
            $pp->{'region'}[$curRegion]{'end'}[$n]{'offset'} = $fields[3];
        }

        if (/^mark /) {
            @fields = split(/  */, $_);
            die "Illegal mark entry, line $line" if ($#fields != 5);
            my $id = $fields[1];
            $pp->{'mark'}[$id]{'addr'} = $fields[2];
            $pp->{'mark'}[$id]{'inStart'} = $fields[3];
            $pp->{'mark'}[$id]{'inEnd'} = $fields[4];
            $pp->{'mark'}[$id]{'isNop'} = $fields[5];
        }

        if (/^totalIcount /) {
            @fields = split(/  */, $_);
            die "Illegal totalIcount entry, line $line" if ($#fields != 1);
            $pp->{'totalIcount'} = $fields[1];
        }
    }
}


##
## Dump all the data to stdout
##
sub DumpPPData # ( \%pp )
{
    my $pp = shift;
    my $i;
    my $j;

    foreach $i (1..NRegions($pp)) {
        my $region = GetRegion($pp, $i);
        print "Region $i, weight " . GetRegionWeight($region) .
            ", length " . GetRegionLength($region) .
            ", offset " . GetRegionInstrOffset($region) . "\n";

        foreach $j (0..NStartPoints($region)) {
            my $start = GetStartPoint($region, $j);
            my $mark = GetPointMarkId($start);
            print "  start " . GetPointMarkAddr($pp, $start) .
                " ($mark), ecount " . GetPointExeCount($start) .
                ", slice-offset " . GetPointInstrOffset($start) . "\n";
        }

        foreach $j (0..NEndPoints($region)) {
            my $end = GetEndPoint($region, $j);
            my $mark = GetPointMarkId($end);
            print "  end   " . GetPointMarkAddr($pp, $end) .
                " ($mark), ecount " . GetPointExeCount($end) .
                ", slice-offset " . GetPointInstrOffset($end) . "\n";
        }
        print "\n";
    }

    print "Marked instructions:\n";
    foreach $i (1..NMarkedInstrs($pp)) {
        my $mark = GetMark($pp, $i);
        printf "  %02d  %s  ", $i, GetMarkAddr($mark);

        if (MarkIsInStart($mark)) {
            print " S";
        }
        else {
            print "  ";
        }

        if (MarkIsInEnd($mark)) {
            print " E";
        }
        else {
            print "  ";
        }

        if (MarkIsNOP($mark)) {
            print " Y";
        }
        else {
            print " N";
        }

        print "\n";
    }

    print "\nTotal dynamic icount:  " . TotalDynamicIcount($pp) . "\n";
}

1;
