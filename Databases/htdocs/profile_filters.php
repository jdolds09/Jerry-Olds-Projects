<?php
    // Connect to database
    include('connection.php');
                
    // Get transactions
        $active_user = $_SESSION['active_user_id'];
        $result = mysqli_query($con, "SELECT * FROM transactions WHERE PROFILE_ID = '$active_user'");

    // If no transactions made
        if(mysqli_num_rows($result) == 0)
                echo '<h2 align = "center">No Transactions Made</h2>';

    // Transactions
        else
        {
        // Table
            echo '<table border = "1" align = "center">';
            echo '<tr>';
            echo '<th>Date</th>';
            echo '<th>Animal Name</th>';
            echo '<th>Transaction Type</th>';
            echo '</tr>';

        // Variables
            $date = $_SESSION['date'];
            $a_name = $_SESSION['a_name'];
            $t_type = $_SESSION['transaction_type'];

            while($row = $result->fetch_assoc())
            {
            // Variables
                $t_date = $row['Transaction_Date']; 
                $animal_name = $row['Animal_Name'];
                $transaction_type = $row['Transaction_Type'];
                $donation_amount = $row['Donation_Amount'];
                
                if($date != "" && $a_name != "" && $t_type != "")
                {
                    if($date == $t_date && $a_name == $animal_name)
                    {
                        if($t_type == 1)
                        {
                        // Adoptions
                            if($transaction_type == "Adoption")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }

                        // Donations
                            if($transaction_type == "Donation")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . ' ($' . $donation_amount . ')</th>';
                                echo '</tr>';
                            }

                        // Inquiries
                            if($transaction_type == "Inquiry")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }
                        }

                        else if($t_type == 2)
                        {
                        // Adoptions
                            if($transaction_type == "Adoption")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }

                        // Donations
                            if($transaction_type == "Donation")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . ' ($' . $donation_amount . ')</th>';
                                echo '</tr>';
                            }

                        // Likes
                            if($transaction_type == "Like")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }
                        }

                        else if($t_type == 3)
                        {
                        // Donations
                            if($transaction_type == "Donation")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . ' ($' . $donation_amount . ')</th>';
                                echo '</tr>';
                            }

                        // Inquiries
                            if($transaction_type == "Inquiry")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }

                        // Likes
                            if($transaction_type == "Like")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }
                        }

                        else if($t_type == 4)
                        {
                        // Adoptions
                            if($transaction_type == "Adoption")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }

                        // Donations
                            if($transaction_type == "Donation")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . ' ($' . $donation_amount . ')</th>';
                                echo '</tr>';
                            }
                        }

                        else if($t_type == 5)
                        {
                        // Adoptions
                            if($transaction_type == "Adoption")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }

                        // Inquiries
                            if($transaction_type == "Inquiry")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }
                        }

                        else if($t_type == 6)
                        {
                        // Adoptions
                            if($transaction_type == "Adoption")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }

                        // Likes
                            if($transaction_type == "Like")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }
                        }

                        else if($t_type == 7)
                        {
                        // Donations
                            if($transaction_type == "Donation")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . ' ($' . $donation_amount . ')</th>';
                                echo '</tr>';
                            }

                        // Inquiries
                            if($transaction_type == "Inquiry")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }
                        }

                        else if($t_type == 8)
                        {
                        // Donations
                            if($transaction_type == "Donation")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . ' ($' . $donation_amount . ')</th>';
                                echo '</tr>';
                            }

                        // Likes
                            if($transaction_type == "Like")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }
                        }

                        else if($t_type == 9)
                        {
                        // Inquiries
                            if($transaction_type == "Inquiry")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }

                        // Likes
                            if($transaction_type == "Like")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }
                        }

                        else if($t_type == 10)
                        {
                        // Adoptions
                            if($transaction_type == "Adoption")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }
                        }

                        else if($t_type == 11)
                        {
                        // Donations
                            if($transaction_type == "Donation")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . ' ($' . $donation_amount . ')</th>';
                                echo '</tr>';
                            }
                        }

                        else if($t_type == 12)
                        {
                        // Inquiries
                            if($transaction_type == "Inquiry")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }
                        }

                        else
                        {
                        // Likes
                            if($transaction_type == "Like")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }
                        }
                    }
                }

                else if($date != "" && $a_name != "")
                {
                    if($date == $t_date && $a_name == $animal_name)
                    {
                    // Adoptions
                        if($transaction_type == "Adoption")
                        {
                            echo '<tr>';
                            echo '<th>' . $t_date . '</th>';
                            echo '<th>' . $animal_name . '</th>';
                            echo '<th>' . $transaction_type . '</th>';
                            echo '</tr>';
                        }

                    // Donations
                        if($transaction_type == "Donation")
                        {
                            echo '<tr>';
                            echo '<th>' . $t_date . '</th>';
                            echo '<th>' . $animal_name . '</th>';
                            echo '<th>' . $transaction_type . ' ($' . $donation_amount . ')</th>';
                            echo '</tr>';
                        }

                    // Inquiries
                        if($transaction_type == "Inquiry")
                        {
                            echo '<tr>';
                            echo '<th>' . $t_date . '</th>';
                            echo '<th>' . $animal_name . '</th>';
                            echo '<th>' . $transaction_type . '</th>';
                            echo '</tr>';
                        }

                    // Likes
                        if($transaction_type == "Like")
                        {
                            echo '<tr>';
                            echo '<th>' . $t_date . '</th>';
                            echo '<th>' . $animal_name . '</th>';
                            echo '<th>' . $transaction_type . '</th>';
                            echo '</tr>';
                        }
                    }
                }

                else if($date != "" && $t_type != "")
                {
                    if($date == $t_date)
                    {
                        if($t_type == 1)
                        {
                        // Adoptions
                            if($transaction_type == "Adoption")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }

                        // Donations
                            if($transaction_type == "Donation")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . ' ($' . $donation_amount . ')</th>';
                                echo '</tr>';
                            }

                        // Inquiries
                            if($transaction_type == "Inquiry")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }
                        }

                        else if($t_type == 2)
                        {
                        // Adoptions
                            if($transaction_type == "Adoption")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }

                        // Donations
                            if($transaction_type == "Donation")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . ' ($' . $donation_amount . ')</th>';
                                echo '</tr>';
                            }

                        // Likes
                            if($transaction_type == "Like")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }
                        }

                        else if($t_type == 3)
                        {
                        // Donations
                            if($transaction_type == "Donation")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . ' ($' . $donation_amount . ')</th>';
                                echo '</tr>';
                            }

                        // Inquiries
                            if($transaction_type == "Inquiry")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }

                        // Likes
                            if($transaction_type == "Like")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }
                        }

                        else if($t_type == 4)
                        {
                        // Adoptions
                            if($transaction_type == "Adoption")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }

                        // Donations
                            if($transaction_type == "Donation")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . ' ($' . $donation_amount . ')</th>';
                                echo '</tr>';
                            }
                        }

                        else if($t_type == 5)
                        {
                        // Adoptions
                            if($transaction_type == "Adoption")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }

                        // Inquiries
                            if($transaction_type == "Inquiry")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }
                        }

                        else if($t_type == 6)
                        {
                        // Adoptions
                            if($transaction_type == "Adoption")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }

                        // Likes
                            if($transaction_type == "Like")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }
                        }

                        else if($t_type == 7)
                        {
                        // Donations
                            if($transaction_type == "Donation")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . ' ($' . $donation_amount . ')</th>';
                                echo '</tr>';
                            }

                        // Inquiries
                            if($transaction_type == "Inquiry")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }
                        }

                        else if($t_type == 8)
                        {
                        // Donations
                            if($transaction_type == "Donation")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . ' ($' . $donation_amount . ')</th>';
                                echo '</tr>';
                            }

                        // Likes
                            if($transaction_type == "Like")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }
                        }

                        else if($t_type == 9)
                        {
                        // Inquiries
                            if($transaction_type == "Inquiry")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }

                        // Likes
                            if($transaction_type == "Like")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }
                        }

                        else if($t_type == 10)
                        {
                        // Adoptions
                            if($transaction_type == "Adoption")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }
                        }

                        else if($t_type == 11)
                        {
                        // Donations
                            if($transaction_type == "Donation")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . ' ($' . $donation_amount . ')</th>';
                                echo '</tr>';
                            }
                        }

                        else if($t_type == 12)
                        {
                        // Inquiries
                            if($transaction_type == "Inquiry")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }
                        }

                        else
                        {
                        // Likes
                            if($transaction_type == "Like")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }
                        }
                    }
                }

                else if($a_name != "" && $t_type != "")
                {
                    if($a_name == $animal_name)
                    {
                        if($t_type == 1)
                        {
                        // Adoptions
                            if($transaction_type == "Adoption")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }

                        // Donations
                            if($transaction_type == "Donation")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . ' ($' . $donation_amount . ')</th>';
                                echo '</tr>';
                            }

                        // Inquiries
                            if($transaction_type == "Inquiry")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }
                        }

                        else if($t_type == 2)
                        {
                        // Adoptions
                            if($transaction_type == "Adoption")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }

                        // Donations
                            if($transaction_type == "Donation")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . ' ($' . $donation_amount . ')</th>';
                                echo '</tr>';
                            }

                        // Likes
                            if($transaction_type == "Like")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }
                        }

                        else if($t_type == 3)
                        {
                        // Donations
                            if($transaction_type == "Donation")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . ' ($' . $donation_amount . ')</th>';
                                echo '</tr>';
                            }

                        // Inquiries
                            if($transaction_type == "Inquiry")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }

                        // Likes
                            if($transaction_type == "Like")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }
                        }

                        else if($t_type == 4)
                        {
                        // Adoptions
                            if($transaction_type == "Adoption")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }

                        // Donations
                            if($transaction_type == "Donation")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . ' ($' . $donation_amount . ')</th>';
                                echo '</tr>';
                            }
                        }

                        else if($t_type == 5)
                        {
                        // Adoptions
                            if($transaction_type == "Adoption")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }

                        // Inquiries
                            if($transaction_type == "Inquiry")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }
                        }

                        else if($t_type == 6)
                        {
                        // Adoptions
                            if($transaction_type == "Adoption")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }

                        // Likes
                            if($transaction_type == "Like")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }
                        }

                        else if($t_type == 7)
                        {
                        // Donations
                            if($transaction_type == "Donation")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . ' ($' . $donation_amount . ')</th>';
                                echo '</tr>';
                            }

                        // Inquiries
                            if($transaction_type == "Inquiry")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }
                        }

                        else if($t_type == 8)
                        {
                        // Donations
                            if($transaction_type == "Donation")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . ' ($' . $donation_amount . ')</th>';
                                echo '</tr>';
                            }

                        // Likes
                            if($transaction_type == "Like")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }
                        }

                        else if($t_type == 9)
                        {
                        // Inquiries
                            if($transaction_type == "Inquiry")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }

                        // Likes
                            if($transaction_type == "Like")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }
                        }

                        else if($t_type == 10)
                        {
                        // Adoptions
                            if($transaction_type == "Adoption")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }
                        }

                        else if($t_type == 11)
                        {
                        // Donations
                            if($transaction_type == "Donation")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . ' ($' . $donation_amount . ')</th>';
                                echo '</tr>';
                            }
                        }

                        else if($t_type == 12)
                        {
                        // Inquiries
                            if($transaction_type == "Inquiry")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }
                        }

                        else
                        {
                        // Likes
                            if($transaction_type == "Like")
                            {
                                echo '<tr>';
                                echo '<th>' . $t_date . '</th>';
                                echo '<th>' . $animal_name . '</th>';
                                echo '<th>' . $transaction_type . '</th>';
                                echo '</tr>';
                            }
                        }
                    }
                }

                else if($date != "")
                {
                    if($date == $t_date)
                    {
                    // Adoptions
                        if($transaction_type == "Adoption")
                        {
                            echo '<tr>';
                            echo '<th>' . $t_date . '</th>';
                            echo '<th>' . $animal_name . '</th>';
                            echo '<th>' . $transaction_type . '</th>';
                            echo '</tr>';
                        }

                    // Donations
                        if($transaction_type == "Donation")
                        {
                            echo '<tr>';
                            echo '<th>' . $t_date . '</th>';
                            echo '<th>' . $animal_name . '</th>';
                            echo '<th>' . $transaction_type . ' ($' . $donation_amount . ')</th>';
                            echo '</tr>';
                        }

                    // Inquiries
                        if($transaction_type == "Inquiry")
                        {
                            echo '<tr>';
                            echo '<th>' . $t_date . '</th>';
                            echo '<th>' . $animal_name . '</th>';
                            echo '<th>' . $transaction_type . '</th>';
                            echo '</tr>';
                        }

                    // Likes
                        if($transaction_type == "Like")
                        {
                            echo '<tr>';
                            echo '<th>' . $t_date . '</th>';
                            echo '<th>' . $animal_name . '</th>';
                            echo '<th>' . $transaction_type . '</th>';
                            echo '</tr>';
                        }
                    }
                }

                else if($a_name != "")
                {
                    if($a_name == $animal_name)
                    {
                    // Adoptions
                        if($transaction_type == "Adoption")
                        {
                            echo '<tr>';
                            echo '<th>' . $t_date . '</th>';
                            echo '<th>' . $animal_name . '</th>';
                            echo '<th>' . $transaction_type . '</th>';
                            echo '</tr>';
                        }

                    // Donations
                        if($transaction_type == "Donation")
                        {
                            echo '<tr>';
                            echo '<th>' . $t_date . '</th>';
                            echo '<th>' . $animal_name . '</th>';
                            echo '<th>' . $transaction_type . ' ($' . $donation_amount . ')</th>';
                            echo '</tr>';
                        }

                    // Inquiries
                        if($transaction_type == "Inquiry")
                        {
                            echo '<tr>';
                            echo '<th>' . $t_date . '</th>';
                            echo '<th>' . $animal_name . '</th>';
                            echo '<th>' . $transaction_type . '</th>';
                            echo '</tr>';
                        }

                    // Likes
                        if($transaction_type == "Like")
                        {
                            echo '<tr>';
                            echo '<th>' . $t_date . '</th>';
                            echo '<th>' . $animal_name . '</th>';
                            echo '<th>' . $transaction_type . '</th>';
                            echo '</tr>';
                        }
                    }
                }

                else if($t_type != "")
                {
                    if($t_type == 1)
                    {
                    // Adoptions
                        if($transaction_type == "Adoption")
                        {
                            echo '<tr>';
                            echo '<th>' . $t_date . '</th>';
                            echo '<th>' . $animal_name . '</th>';
                            echo '<th>' . $transaction_type . '</th>';
                            echo '</tr>';
                        }

                    // Donations
                        if($transaction_type == "Donation")
                        {
                            echo '<tr>';
                            echo '<th>' . $t_date . '</th>';
                            echo '<th>' . $animal_name . '</th>';
                            echo '<th>' . $transaction_type . ' ($' . $donation_amount . ')</th>';
                            echo '</tr>';
                        }

                    // Inquiries
                        if($transaction_type == "Inquiry")
                        {
                            echo '<tr>';
                            echo '<th>' . $t_date . '</th>';
                            echo '<th>' . $animal_name . '</th>';
                            echo '<th>' . $transaction_type . '</th>';
                            echo '</tr>';
                        }
                    }

                    else if($t_type == 2)
                    {
                    // Adoptions
                        if($transaction_type == "Adoption")
                        {
                            echo '<tr>';
                            echo '<th>' . $t_date . '</th>';
                            echo '<th>' . $animal_name . '</th>';
                            echo '<th>' . $transaction_type . '</th>';
                            echo '</tr>';
                        }

                    // Donations
                        if($transaction_type == "Donation")
                        {
                            echo '<tr>';
                            echo '<th>' . $t_date . '</th>';
                            echo '<th>' . $animal_name . '</th>';
                            echo '<th>' . $transaction_type . ' ($' . $donation_amount . ')</th>';
                            echo '</tr>';
                        }

                    // Likes
                        if($transaction_type == "Like")
                        {
                            echo '<tr>';
                            echo '<th>' . $t_date . '</th>';
                            echo '<th>' . $animal_name . '</th>';
                            echo '<th>' . $transaction_type . '</th>';
                            echo '</tr>';
                        }
                    }

                    else if($t_type == 3)
                    {
                    // Donations
                        if($transaction_type == "Donation")
                        {
                            echo '<tr>';
                            echo '<th>' . $t_date . '</th>';
                            echo '<th>' . $animal_name . '</th>';
                            echo '<th>' . $transaction_type . ' ($' . $donation_amount . ')</th>';
                            echo '</tr>';
                        }

                    // Inquiries
                        if($transaction_type == "Inquiry")
                        {
                            echo '<tr>';
                            echo '<th>' . $t_date . '</th>';
                            echo '<th>' . $animal_name . '</th>';
                            echo '<th>' . $transaction_type . '</th>';
                            echo '</tr>';
                        }

                    // Likes
                        if($transaction_type == "Like")
                        {
                            echo '<tr>';
                            echo '<th>' . $t_date . '</th>';
                            echo '<th>' . $animal_name . '</th>';
                            echo '<th>' . $transaction_type . '</th>';
                            echo '</tr>';
                        }
                    }

                    else if($t_type == 4)
                    {
                    // Adoptions
                        if($transaction_type == "Adoption")
                        {
                            echo '<tr>';
                            echo '<th>' . $t_date . '</th>';
                            echo '<th>' . $animal_name . '</th>';
                            echo '<th>' . $transaction_type . '</th>';
                            echo '</tr>';
                        }

                    // Donations
                        if($transaction_type == "Donation")
                        {
                            echo '<tr>';
                            echo '<th>' . $t_date . '</th>';
                            echo '<th>' . $animal_name . '</th>';
                            echo '<th>' . $transaction_type . ' ($' . $donation_amount . ')</th>';
                            echo '</tr>';
                        }
                    }

                    else if($t_type == 5)
                    {
                    // Adoptions
                        if($transaction_type == "Adoption")
                        {
                            echo '<tr>';
                            echo '<th>' . $t_date . '</th>';
                            echo '<th>' . $animal_name . '</th>';
                            echo '<th>' . $transaction_type . '</th>';
                            echo '</tr>';
                        }

                    // Inquiries
                        if($transaction_type == "Inquiry")
                        {
                            echo '<tr>';
                            echo '<th>' . $t_date . '</th>';
                            echo '<th>' . $animal_name . '</th>';
                            echo '<th>' . $transaction_type . '</th>';
                            echo '</tr>';
                        }
                    }

                    else if($t_type == 6)
                    {
                    // Adoptions
                        if($transaction_type == "Adoption")
                        {
                            echo '<tr>';
                            echo '<th>' . $t_date . '</th>';
                            echo '<th>' . $animal_name . '</th>';
                            echo '<th>' . $transaction_type . '</th>';
                            echo '</tr>';
                        }

                    // Likes
                        if($transaction_type == "Like")
                        {
                            echo '<tr>';
                            echo '<th>' . $t_date . '</th>';
                            echo '<th>' . $animal_name . '</th>';
                            echo '<th>' . $transaction_type . '</th>';
                            echo '</tr>';
                        }
                    }

                    else if($t_type == 7)
                    {
                    // Donations
                        if($transaction_type == "Donation")
                        {
                            echo '<tr>';
                            echo '<th>' . $t_date . '</th>';
                            echo '<th>' . $animal_name . '</th>';
                            echo '<th>' . $transaction_type . ' ($' . $donation_amount . ')</th>';
                            echo '</tr>';
                        }

                    // Inquiries
                        if($transaction_type == "Inquiry")
                        {
                            echo '<tr>';
                            echo '<th>' . $t_date . '</th>';
                            echo '<th>' . $animal_name . '</th>';
                            echo '<th>' . $transaction_type . '</th>';
                            echo '</tr>';
                        }
                    }

                    else if($t_type == 8)
                    {
                    // Donations
                        if($transaction_type == "Donation")
                        {
                            echo '<tr>';
                            echo '<th>' . $t_date . '</th>';
                            echo '<th>' . $animal_name . '</th>';
                            echo '<th>' . $transaction_type . ' ($' . $donation_amount . ')</th>';
                            echo '</tr>';
                        }

                    // Likes
                        if($transaction_type == "Like")
                        {
                            echo '<tr>';
                            echo '<th>' . $t_date . '</th>';
                            echo '<th>' . $animal_name . '</th>';
                            echo '<th>' . $transaction_type . '</th>';
                            echo '</tr>';
                        }
                    }

                    else if($t_type == 9)
                    {
                    // Inquiries
                        if($transaction_type == "Inquiry")
                        {
                            echo '<tr>';
                            echo '<th>' . $t_date . '</th>';
                            echo '<th>' . $animal_name . '</th>';
                            echo '<th>' . $transaction_type . '</th>';
                            echo '</tr>';
                        }

                    // Likes
                        if($transaction_type == "Like")
                        {
                            echo '<tr>';
                            echo '<th>' . $t_date . '</th>';
                            echo '<th>' . $animal_name . '</th>';
                            echo '<th>' . $transaction_type . '</th>';
                            echo '</tr>';
                        }
                    }

                    else if($t_type == 10)
                    {
                    // Adoptions
                        if($transaction_type == "Adoption")
                        {
                            echo '<tr>';
                            echo '<th>' . $t_date . '</th>';
                            echo '<th>' . $animal_name . '</th>';
                            echo '<th>' . $transaction_type . '</th>';
                            echo '</tr>';
                        }
                    }

                    else if($t_type == 11)
                    {
                    // Donations
                        if($transaction_type == "Donation")
                        {
                            echo '<tr>';
                            echo '<th>' . $t_date . '</th>';
                            echo '<th>' . $animal_name . '</th>';
                            echo '<th>' . $transaction_type . ' ($' . $donation_amount . ')</th>';
                            echo '</tr>';
                        }
                    }

                    else if($t_type == 12)
                    {
                    // Inquiries
                        if($transaction_type == "Inquiry")
                        {
                            echo '<tr>';
                            echo '<th>' . $t_date . '</th>';
                            echo '<th>' . $animal_name . '</th>';
                            echo '<th>' . $transaction_type . '</th>';
                            echo '</tr>';
                        }
                    }

                    else
                    {
                    // Likes
                        if($transaction_type == "Like")
                        {
                            echo '<tr>';
                            echo '<th>' . $t_date . '</th>';
                            echo '<th>' . $animal_name . '</th>';
                            echo '<th>' . $transaction_type . '</th>';
                            echo '</tr>';
                        }
                    }
                }

                else
                {
                // Adoptions
                    if($transaction_type == "Adoption")
                    {
                        echo '<tr>';
                        echo '<th>' . $t_date . '</th>';
                        echo '<th>' . $animal_name . '</th>';
                        echo '<th>' . $transaction_type . '</th>';
                        echo '</tr>';
                    }

                // Donations
                    if($transaction_type == "Donation")
                    {
                        echo '<tr>';
                        echo '<th>' . $t_date . '</th>';
                        echo '<th>' . $animal_name . '</th>';
                        echo '<th>' . $transaction_type . ' ($' . $donation_amount . ')</th>';
                        echo '</tr>';
                    }

                // Inquiries
                    if($transaction_type == "Inquiry")
                    {
                        echo '<tr>';
                        echo '<th>' . $t_date . '</th>';
                        echo '<th>' . $animal_name . '</th>';
                        echo '<th>' . $transaction_type . '</th>';
                        echo '</tr>';
                    }

                // Likes
                    if($transaction_type == "Like")
                    {
                        echo '<tr>';
                        echo '<th>' . $t_date . '</th>';
                        echo '<th>' . $animal_name . '</th>';
                        echo '<th>' . $transaction_type . '</th>';
                        echo '</tr>';
                    }
                }
            }
        }
?>