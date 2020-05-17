<?php

    // Table
        echo '<table border = "1" align = "center">';
        echo '<tr>';
        echo '<th>Date</th>';
        echo '<th>Name (Profile ID)</th>';
        echo '<th>Animal Name (Animal ID)</th>';
        echo '<th>Question</th>';
        echo '<th>Answer</th>';
        echo '</tr>';

    // Get inquriries
        $result = mysqli_query($con, "SELECT INQUIRY_ID, PROFILE_ID, First_Name, Last_Name, Animal_Name, ANIMAL_ID, Question, Answer, Inquiry_Date from inquiries WHERE Answer IS NULL");
        $result2 = mysqli_query($con, "SELECT INQUIRY_ID, PROFILE_ID, First_Name, Last_Name, Animal_Name, ANIMAL_ID, Question, Answer, Inquiry_Date from inquiries WHERE Answer IS NOT NULL");

    // Variables
        $date = $_SESSION['inquiry_date'];
        $fname = $_SESSION['inquiry_first_name'];
        $lname = $_SESSION['inquiry_last_name'];
        $a_name = $_SESSION['inquiry_a_name'];
        
    // Display unanswered inquiries on top
        if(mysqli_num_rows($result) > 0)
        {
            while($row = $result->fetch_assoc())
            {
            // Variables
                $i_date = $row['Inquiry_Date'];
                $first_name = $row['First_Name'];
                $last_name = $row['Last_Name'];
                $animal_name =$row['Animal_Name'];
                $profile_id = $row['PROFILE_ID'];
                $animal_id = $row['ANIMAL_ID'];

                if($date != "" && $fname != "" && $lname != "" && $a_name != "")
                {
                    if($date == $i_date && $fname == $first_name && $lname == $last_name && $a_name == $animal_name)
                    {
                        echo '<tr>';
                        echo '<th>' . $i_date . '</th>'; 
                        echo '<th>' . $first_name . ' ' . $last_name . ' (#' . $profile_id . ')</th>';
                        echo '<th>' . $animal_name . ' (#' . $animal_id . ')</th>';   
                        echo '<th>' . $row['Question'] . '</th>';  
                        echo '<th><li style = "list-style: none"><a class = "answer" href = "?link=' . $row['INQUIRY_ID'] . '">Answer Inquiry</a></li></th>';
                        echo '</tr>';
                    }
                }

                else if($date != "" && $fname != "" && $lname != "")
                {
                    if($date == $i_date && $fname == $first_name && $lname == $last_name)
                    {
                        echo '<tr>';
                        echo '<th>' . $i_date . '</th>'; 
                        echo '<th>' . $first_name . ' ' . $last_name . ' (#' . $profile_id . ')</th>';
                        echo '<th>' . $animal_name . ' (#' . $animal_id . ')</th>';   
                        echo '<th>' . $row['Question'] . '</th>';  
                        echo '<th><li style = "list-style: none"><a class = "answer" href = "?link=' . $row['INQUIRY_ID'] . '">Answer Inquiry</a></li></th>';
                        echo '</tr>';
                    }
                }

                else if($date != "" && $fname != "" && $a_name != "")
                {
                    if($date == $i_date && $fname == $first_name && $a_name == $animal_name)
                    {
                        echo '<tr>';
                        echo '<th>' . $i_date . '</th>'; 
                        echo '<th>' . $first_name . ' ' . $last_name . ' (#' . $profile_id . ')</th>';
                        echo '<th>' . $animal_name . ' (#' . $animal_id . ')</th>';   
                        echo '<th>' . $row['Question'] . '</th>';  
                        echo '<th><li style = "list-style: none"><a class = "answer" href = "?link=' . $row['INQUIRY_ID'] . '">Answer Inquiry</a></li></th>';
                        echo '</tr>';
                    }
                }

                else if($date != "" && $lname != "" && $a_name != "")
                {
                    if($date == $i_date && $lname == $last_name && $a_name == $animal_name)
                    {
                        echo '<tr>';
                        echo '<th>' . $i_date . '</th>'; 
                        echo '<th>' . $first_name . ' ' . $last_name . ' (#' . $profile_id . ')</th>';
                        echo '<th>' . $animal_name . ' (#' . $animal_id . ')</th>';   
                        echo '<th>' . $row['Question'] . '</th>';  
                        echo '<th><li style = "list-style: none"><a class = "answer" href = "?link=' . $row['INQUIRY_ID'] . '">Answer Inquiry</a></li></th>';
                        echo '</tr>';
                    }
                }

                else if($fname != "" && $lname != "" && $a_name != "")
                {
                    if($fname == $first_name && $lname == $last_name && $a_name == $animal_name)
                    {
                        echo '<tr>';
                        echo '<th>' . $i_date . '</th>'; 
                        echo '<th>' . $first_name . ' ' . $last_name . ' (#' . $profile_id . ')</th>';
                        echo '<th>' . $animal_name . ' (#' . $animal_id . ')</th>';   
                        echo '<th>' . $row['Question'] . '</th>';  
                        echo '<th><li style = "list-style: none"><a class = "answer" href = "?link=' . $row['INQUIRY_ID'] . '">Answer Inquiry</a></li></th>';
                        echo '</tr>';
                    }
                }

                else if($date != "" && $fname != "")
                {
                    if($date == $i_date && $fname == $first_name)
                    {
                        echo '<tr>';
                        echo '<th>' . $i_date . '</th>'; 
                        echo '<th>' . $first_name . ' ' . $last_name . ' (#' . $profile_id . ')</th>';
                        echo '<th>' . $animal_name . ' (#' . $animal_id . ')</th>';   
                        echo '<th>' . $row['Question'] . '</th>';  
                        echo '<th><li style = "list-style: none"><a class = "answer" href = "?link=' . $row['INQUIRY_ID'] . '">Answer Inquiry</a></li></th>';
                        echo '</tr>';
                    }
                }

                else if($date != "" && $lname != "")
                {
                    if($date == $i_date && $lname == $last_name)
                    {
                        echo '<tr>';
                        echo '<th>' . $i_date . '</th>'; 
                        echo '<th>' . $first_name . ' ' . $last_name . ' (#' . $profile_id . ')</th>';
                        echo '<th>' . $animal_name . ' (#' . $animal_id . ')</th>';   
                        echo '<th>' . $row['Question'] . '</th>';  
                        echo '<th><li style = "list-style: none"><a class = "answer" href = "?link=' . $row['INQUIRY_ID'] . '">Answer Inquiry</a></li></th>';
                        echo '</tr>';
                    }
                }

                else if($date != "" && $a_name != "")
                {
                    if($date == $i_date && $a_name == $animal_name)
                    {
                        echo '<tr>';
                        echo '<th>' . $i_date . '</th>'; 
                        echo '<th>' . $first_name . ' ' . $last_name . ' (#' . $profile_id . ')</th>';
                        echo '<th>' . $animal_name . ' (#' . $animal_id . ')</th>';   
                        echo '<th>' . $row['Question'] . '</th>';  
                        echo '<th><li style = "list-style: none"><a class = "answer" href = "?link=' . $row['INQUIRY_ID'] . '">Answer Inquiry</a></li></th>';
                        echo '</tr>';
                    }
                }

                else if($fname != "" && $lname != "")
                {
                    if($fname == $first_name && $lname == $last_name)
                    {
                        echo '<tr>';
                        echo '<th>' . $i_date . '</th>'; 
                        echo '<th>' . $first_name . ' ' . $last_name . ' (#' . $profile_id . ')</th>';
                        echo '<th>' . $animal_name . ' (#' . $animal_id . ')</th>';   
                        echo '<th>' . $row['Question'] . '</th>';  
                        echo '<th><li style = "list-style: none"><a class = "answer" href = "?link=' . $row['INQUIRY_ID'] . '">Answer Inquiry</a></li></th>';
                        echo '</tr>';
                    }
                }

                else if($fname != "" && $a_name != "")
                {
                    if($fname == $first_name && $a_name == $animal_name)
                    {
                        echo '<tr>';
                        echo '<th>' . $i_date . '</th>'; 
                        echo '<th>' . $first_name . ' ' . $last_name . ' (#' . $profile_id . ')</th>';
                        echo '<th>' . $animal_name . ' (#' . $animal_id . ')</th>';   
                        echo '<th>' . $row['Question'] . '</th>';  
                        echo '<th><li style = "list-style: none"><a class = "answer" href = "?link=' . $row['INQUIRY_ID'] . '">Answer Inquiry</a></li></th>';
                        echo '</tr>';
                    }
                }

                else if($lname != "" && $a_name != "")
                {
                    if($lname == $last_name && $a_name == $animal_name)
                    {
                        echo '<tr>';
                        echo '<th>' . $i_date . '</th>'; 
                        echo '<th>' . $first_name . ' ' . $last_name . ' (#' . $profile_id . ')</th>';
                        echo '<th>' . $animal_name . ' (#' . $animal_id . ')</th>';   
                        echo '<th>' . $row['Question'] . '</th>';  
                        echo '<th><li style = "list-style: none"><a class = "answer" href = "?link=' . $row['INQUIRY_ID'] . '">Answer Inquiry</a></li></th>';
                        echo '</tr>';
                    }
                }

                else if($date != "")
                {
                    if($date == $i_date)
                    {
                        echo '<tr>';
                        echo '<th>' . $i_date . '</th>'; 
                        echo '<th>' . $first_name . ' ' . $last_name . ' (#' . $profile_id . ')</th>';
                        echo '<th>' . $animal_name . ' (#' . $animal_id . ')</th>';   
                        echo '<th>' . $row['Question'] . '</th>';  
                        echo '<th><li style = "list-style: none"><a class = "answer" href = "?link=' . $row['INQUIRY_ID'] . '">Answer Inquiry</a></li></th>';
                        echo '</tr>';
                    }
                }

                else if($fname != "")
                {
                    if($fname == $first_name)
                    {
                        echo '<tr>';
                        echo '<th>' . $i_date . '</th>'; 
                        echo '<th>' . $first_name . ' ' . $last_name . ' (#' . $profile_id . ')</th>';
                        echo '<th>' . $animal_name . ' (#' . $animal_id . ')</th>';   
                        echo '<th>' . $row['Question'] . '</th>';  
                        echo '<th><li style = "list-style: none"><a class = "answer" href = "?link=' . $row['INQUIRY_ID'] . '">Answer Inquiry</a></li></th>';
                        echo '</tr>';
                    }
                }

                else if($lname != "")
                {
                    if($lname == $last_name)
                    {
                        echo '<tr>';
                        echo '<th>' . $i_date . '</th>'; 
                        echo '<th>' . $first_name . ' ' . $last_name . ' (#' . $profile_id . ')</th>';
                        echo '<th>' . $animal_name . ' (#' . $animal_id . ')</th>';   
                        echo '<th>' . $row['Question'] . '</th>';  
                        echo '<th><li style = "list-style: none"><a class = "answer" href = "?link=' . $row['INQUIRY_ID'] . '">Answer Inquiry</a></li></th>';
                        echo '</tr>';
                    }
                }

                else if($a_name != "")
                {
                    if($a_name == $animal_name)
                    {
                        echo '<tr>';
                        echo '<th>' . $i_date . '</th>'; 
                        echo '<th>' . $first_name . ' ' . $last_name . ' (#' . $profile_id . ')</th>';
                        echo '<th>' . $animal_name . ' (#' . $animal_id . ')</th>';   
                        echo '<th>' . $row['Question'] . '</th>';  
                        echo '<th><li style = "list-style: none"><a class = "answer" href = "?link=' . $row['INQUIRY_ID'] . '">Answer Inquiry</a></li></th>';
                        echo '</tr>';
                    }
                }

                else
                {
                    echo '<tr>';
                    echo '<th>' . $i_date . '</th>'; 
                    echo '<th>' . $first_name . ' ' . $last_name . ' (#' . $profile_id . ')</th>';
                    echo '<th>' . $animal_name . ' (#' . $animal_id . ')</th>';   
                    echo '<th>' . $row['Question'] . '</th>';  
                    echo '<th><li style = "list-style: none"><a class = "answer" href = "?link=' . $row['INQUIRY_ID'] . '">Answer Inquiry</a></li></th>';
                    echo '</tr>';
                }
            }
        }

    // Display answered inquiries below unanswered inquiries
        if(mysqli_num_rows($result2) > 0)
        {
            while($row2 = $result2->fetch_assoc())
            {
            // Variables
                $i_date = $row2['Inquiry_Date'];
                $first_name = $row2['First_Name'];
                $last_name = $row2['Last_Name'];
                $animal_name =$row2['Animal_Name'];
                $profile_id = $row2['PROFILE_ID'];
                $animal_id = $row2['ANIMAL_ID'];

                if($date != "" && $fname != "" && $lname != "" && $a_name != "")
                {
                    if($date == $i_date && $fname == $first_name && $lname == $last_name && $a_name == $animal_name)
                    {
                        echo '<tr>';
                        echo '<th>' . $i_date . '</th>'; 
                        echo '<th>' . $first_name . ' ' . $last_name . ' (#' . $profile_id . ')</th>';
                        echo '<th>' . $animal_name . ' (#' . $animal_id . ')</th>';   
                        echo '<th>' . $row2['Question'] . '</th>';  
                        echo '<th>' . $row2['Answer'] . '</th>';
                        echo '</tr>';
                    }
                }

                else if($date != "" && $fname != "" && $lname != "")
                {
                    if($date == $i_date && $fname == $first_name && $lname == $last_name)
                    {
                        echo '<tr>';
                        echo '<th>' . $i_date . '</th>'; 
                        echo '<th>' . $first_name . ' ' . $last_name . ' (#' . $profile_id . ')</th>';
                        echo '<th>' . $animal_name . ' (#' . $animal_id . ')</th>';   
                        echo '<th>' . $row2['Question'] . '</th>';  
                        echo '<th>' . $row2['Answer'] . '</th>';
                        echo '</tr>';
                    }
                }

                else if($date != "" && $fname != "" && $a_name != "")
                {
                    if($date == $i_date && $fname == $first_name && $a_name == $animal_name)
                    {
                        echo '<tr>';
                        echo '<th>' . $i_date . '</th>'; 
                        echo '<th>' . $first_name . ' ' . $last_name . ' (#' . $profile_id . ')</th>';
                        echo '<th>' . $animal_name . ' (#' . $animal_id . ')</th>';   
                        echo '<th>' . $row2['Question'] . '</th>';  
                        echo '<th>' . $row2['Answer'] . '</th>';
                        echo '</tr>';
                    }
                }

                else if($date != "" && $lname != "" && $a_name != "")
                {
                    if($date == $i_date && $lname == $last_name && $a_name == $animal_name)
                    {
                        echo '<tr>';
                        echo '<th>' . $i_date . '</th>'; 
                        echo '<th>' . $first_name . ' ' . $last_name . ' (#' . $profile_id . ')</th>';
                        echo '<th>' . $animal_name . ' (#' . $animal_id . ')</th>';   
                        echo '<th>' . $row2['Question'] . '</th>';  
                        echo '<th>' . $row2['Answer'] . '</th>';
                        echo '</tr>';
                    }
                }

                else if($fname != "" && $lname != "" && $a_name != "")
                {
                    if($fname == $first_name && $lname == $last_name && $a_name == $animal_name)
                    {
                        echo '<tr>';
                        echo '<th>' . $i_date . '</th>'; 
                        echo '<th>' . $first_name . ' ' . $last_name . ' (#' . $profile_id . ')</th>';
                        echo '<th>' . $animal_name . ' (#' . $animal_id . ')</th>';   
                        echo '<th>' . $row2['Question'] . '</th>';  
                        echo '<th>' . $row2['Answer'] . '</th>';
                        echo '</tr>';
                    }
                }

                else if($date != "" && $fname != "")
                {
                    if($date == $i_date && $fname == $first_name)
                    {
                        echo '<tr>';
                        echo '<th>' . $i_date . '</th>'; 
                        echo '<th>' . $first_name . ' ' . $last_name . ' (#' . $profile_id . ')</th>';
                        echo '<th>' . $animal_name . ' (#' . $animal_id . ')</th>';   
                        echo '<th>' . $row2['Question'] . '</th>';  
                        echo '<th>' . $row2['Answer'] . '</th>';
                        echo '</tr>';
                    }
                }

                else if($date != "" && $lname != "")
                {
                    if($date == $i_date && $lname == $last_name)
                    {
                        echo '<tr>';
                        echo '<th>' . $i_date . '</th>'; 
                        echo '<th>' . $first_name . ' ' . $last_name . ' (#' . $profile_id . ')</th>';
                        echo '<th>' . $animal_name . ' (#' . $animal_id . ')</th>';   
                        echo '<th>' . $row2['Question'] . '</th>';  
                        echo '<th>' . $row2['Answer'] . '</th>';
                        echo '</tr>';
                    }
                }

                else if($date != "" && $a_name != "")
                {
                    if($date == $i_date && $a_name == $animal_name)
                    {
                        echo '<tr>';
                        echo '<th>' . $i_date . '</th>'; 
                        echo '<th>' . $first_name . ' ' . $last_name . ' (#' . $profile_id . ')</th>';
                        echo '<th>' . $animal_name . ' (#' . $animal_id . ')</th>';   
                        echo '<th>' . $row2['Question'] . '</th>';  
                        echo '<th>' . $row2['Answer'] . '</th>';
                        echo '</tr>';
                    }
                }

                else if($fname != "" && $lname != "")
                {
                    if($fname == $first_name && $lname == $last_name)
                    {
                        echo '<tr>';
                        echo '<th>' . $i_date . '</th>'; 
                        echo '<th>' . $first_name . ' ' . $last_name . ' (#' . $profile_id . ')</th>';
                        echo '<th>' . $animal_name . ' (#' . $animal_id . ')</th>';   
                        echo '<th>' . $row2['Question'] . '</th>';  
                        echo '<th>' . $row2['Answer'] . '</th>';
                        echo '</tr>';
                    }
                }

                else if($fname != "" && $a_name != "")
                {
                    if($fname == $first_name && $a_name == $animal_name)
                    {
                        echo '<tr>';
                        echo '<th>' . $i_date . '</th>'; 
                        echo '<th>' . $first_name . ' ' . $last_name . ' (#' . $profile_id . ')</th>';
                        echo '<th>' . $animal_name . ' (#' . $animal_id . ')</th>';   
                        echo '<th>' . $row2['Question'] . '</th>';  
                        echo '<th>' . $row2['Answer'] . '</th>';
                        echo '</tr>';
                    }
                }

                else if($lname != "" && $a_name != "")
                {
                    if($lname == $last_name && $a_name == $animal_name)
                    {
                        echo '<tr>';
                        echo '<th>' . $i_date . '</th>'; 
                        echo '<th>' . $first_name . ' ' . $last_name . ' (#' . $profile_id . ')</th>';
                        echo '<th>' . $animal_name . ' (#' . $animal_id . ')</th>';   
                        echo '<th>' . $row2['Question'] . '</th>';  
                        echo '<th>' . $row2['Answer'] . '</th>';
                        echo '</tr>';
                    }
                }

                else if($date != "")
                {
                    if($date == $i_date)
                    {
                        echo '<tr>';
                        echo '<th>' . $i_date . '</th>'; 
                        echo '<th>' . $first_name . ' ' . $last_name . ' (#' . $profile_id . ')</th>';
                        echo '<th>' . $animal_name . ' (#' . $animal_id . ')</th>';   
                        echo '<th>' . $row2['Question'] . '</th>';  
                        echo '<th>' . $row2['Answer'] . '</th>';
                        echo '</tr>';
                    }
                }

                else if($fname != "")
                {
                    if($fname == $first_name)
                    {
                        echo '<tr>';
                        echo '<th>' . $i_date . '</th>'; 
                        echo '<th>' . $first_name . ' ' . $last_name . ' (#' . $profile_id . ')</th>';
                        echo '<th>' . $animal_name . ' (#' . $animal_id . ')</th>';   
                        echo '<th>' . $row2['Question'] . '</th>';  
                        echo '<th>' . $row2['Answer'] . '</th>';
                        echo '</tr>';
                    }
                }

                else if($lname != "")
                {
                    if($lname == $last_name)
                    {
                        echo '<tr>';
                        echo '<th>' . $i_date . '</th>'; 
                        echo '<th>' . $first_name . ' ' . $last_name . ' (#' . $profile_id . ')</th>';
                        echo '<th>' . $animal_name . ' (#' . $animal_id . ')</th>';   
                        echo '<th>' . $row2['Question'] . '</th>';  
                        echo '<th>' . $row2['Answer'] . '</th>';
                        echo '</tr>';
                    }
                }

                else if($a_name != "")
                {
                    if($a_name == $animal_name)
                    {
                        echo '<tr>';
                        echo '<th>' . $i_date . '</th>'; 
                        echo '<th>' . $first_name . ' ' . $last_name . ' (#' . $profile_id . ')</th>';
                        echo '<th>' . $animal_name . ' (#' . $animal_id . ')</th>';   
                        echo '<th>' . $row2['Question'] . '</th>';  
                        echo '<th>' . $row2['Answer'] . '</th>';
                        echo '</tr>';
                    }
                }

                else
                {
                    echo '<tr>';
                    echo '<th>' . $i_date . '</th>'; 
                    echo '<th>' . $first_name . ' ' . $last_name . ' (#' . $profile_id . ')</th>';
                    echo '<th>' . $animal_name . ' (#' . $animal_id . ')</th>';   
                    echo '<th>' . $row2['Question'] . '</th>';  
                    echo '<th>' . $row2['Answer'] . '</th>';
                    echo '</tr>';
                }
            }
        }

    // End of table
        echo '</table>';

?>