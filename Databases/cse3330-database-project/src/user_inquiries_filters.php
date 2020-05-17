<?php
// Variables
    echo '<table border = "1" align = "center">';
    echo '<tr>';
    echo '<th>Date</th>';
    echo '<th>Animal Name</th>';
    echo '<th>Question</th>';
    echo '<th>Answer</th>';
    echo '</tr>';

// Get user inquriries
    $result = mysqli_query($con, "SELECT Inquiry_Date, Animal_Name, Question, Answer from inquiries WHERE PROFILE_ID = '$profile_id'");

// Variables
    $date = $_SESSION['inquiry_date'];
    $a_name = $_SESSION['inquiry_a_name'];

// No inquiries made
    if(mysqli_num_rows($result) == 0)
        echo '<h2 align = "center">No Inquiries made</h2>';


    else
    {
        while($row = $result->fetch_assoc())
        {
        // Variables
            $i_date = $row['Inquiry_Date'];
            $animal_name = $row['Animal_Name'];

            if($date != "" && $a_name != "")
            {
                if($date == $i_date && $a_name == $animal_name)
                {
                    echo '<tr>';
                    echo '<th>' . $row['Inquiry_Date'] . '</th>';
                    echo '<th>' . $row['Animal_Name'] . '</th>';
                    echo '<th>' . $row['Question'] . '</th>';
                    if($row['Answer'] == NULL)
                        echo '<th>Inquiry not answered yet.</th>';
                    else
                        echo '<th>' . $row['Answer'] .'</th>';
                    echo '</tr>';
                }
            }

            else if($date != "")
            {
                if($date == $i_date)
                {
                    echo '<tr>';
                    echo '<th>' . $row['Inquiry_Date'] . '</th>';
                    echo '<th>' . $row['Animal_Name'] . '</th>';
                    echo '<th>' . $row['Question'] . '</th>';
                    if($row['Answer'] == NULL)
                        echo '<th>Inquiry not answered yet.</th>';
                    else
                        echo '<th>' . $row['Answer'] .'</th>';
                    echo '</tr>';
                }
            }

            else if($a_name != "")
            {
                if($a_name == $animal_name)
                {
                    echo '<tr>';
                    echo '<th>' . $row['Inquiry_Date'] . '</th>';
                    echo '<th>' . $row['Animal_Name'] . '</th>';
                    echo '<th>' . $row['Question'] . '</th>';
                    if($row['Answer'] == NULL)
                        echo '<th>Inquiry not answered yet.</th>';
                    else
                        echo '<th>' . $row['Answer'] .'</th>';
                    echo '</tr>';
                }
            }

            else
            {
                echo '<tr>';
                echo '<th>' . $row['Inquiry_Date'] . '</th>';
                echo '<th>' . $row['Animal_Name'] . '</th>';
                echo '<th>' . $row['Question'] . '</th>';
                if($row['Answer'] == NULL)
                    echo '<th>Inquiry not answered yet.</th>';
                else
                    echo '<th>' . $row['Answer'] .'</th>';
                echo '</tr>';
            }
        }
    }

    echo '</table>';
?>