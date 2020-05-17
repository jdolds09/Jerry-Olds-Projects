@ Dalio, Brian A.
@ dalioba
@ 2020-04-23
@-----------------------------------------------------------
@ Compute factorial two different ways.

int original;
int n;
int fact = 1;

@ Get the number we want a factorial of.
write( "Enter a number" );
read( original );

@ Ensure it's acceptable.
if n <= 0 then
  write( "n must be > 0, ", original, "isn't." );
  exit -1
end if;

@ Compute the factorial by counting down and multiplying along
@ the way.

n = original;

while n > 1 do
  fact = fact * n;
  n = n - 1
end while;

@ Were we correct?
if fact == original! then
  @ Yes!  We RULE!
  write( "We agree! ", original, " factorial is ", fact )

else
  @ Blast!  There was a difference.
  write( "Oops!  ", original, "! is ", original!, ", while computed is ", fact )

end if
