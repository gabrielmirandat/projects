%--Progressão V-I em Dó
%  

superior =  {  \clef treble
               \key c \major
               \time 4/4
  <b' d'>2 <c'' e'>2 
}

inferior =  { \clef bass
              \key c \major
              \time 4/4
  
  <g g,>2 <g c>2 
}

\score {
  \new PianoStaff <<
    \set PianoStaff.instrumentName = #"Piano  "
    \new Staff = "superior" \superior
    \new Staff = "inferior" \inferior
  >>
  \layout { }
  \midi { }
}