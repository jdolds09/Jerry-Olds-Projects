<!DOCTYPE html>
<html>
	<head>
        <style>
            a {text-decoration: none;}
            a:visited {text-decoration: none;}
            a:hover {text-decoration: none;}
            a:focus {text-decoration: none;}
            a:hover, .a:active {text-decoration: none;}
            
            .information
            {
                text-align: center;
            }

            button
            {
                margin-right: 5px;
            }

            .buttons
            {
                margin-top: -30px;
                text-align: center;
                margin-bottom: 10px;
            }

            img
            {
                display: block;
                margin: 0 auto;
            }
        </style>

		<meta charset="utf-8">
		<meta name= "viewport" content="width=device-width">
		<meta name= "descriptions" content="User friendly online animal shelter">
		<meta name= "keywords" content="animal, shelter, animal shelter, dogs, cats, adoption, donation, pets">
		<meta name= "author" content="Donovan Almendariz, Jerry Olds">
		<title>Animal Shelter | Animal profile</title>
		<link rel="stylesheet" href= "./style.css">
	</head>
	<body>
		<header>
			<div class= "container">
				<div id= "branding">
					<h1><span class= "highlight">DJ's</span> Animal Shelter</h1>
				</div>
				<nav>
					<ul>
                        <li><a href= "user_home.php">Home</a></li>
                        <li><a href = "animals.php">Animals</a></li>
						<li><a href = "user_inquiries.php">Inquiries</a></li>
                        <li><a href = "profile.php">Profile</a></li>
						<li><a href= "about.php">About</a></li>
					<!--Sign Out-->
                         <li><a href= "?sign_out" >Sign Out</a></li>
                        <?php
						// Sign out
                            if(isset($_GET['sign_out']))
                            {
                            // Set active_user to NULL
                                session_start();
                                $_SESSION['active_user_id'] = NULL;
                            // Re-direct to index page
                                header('Location: index.php');
                            }
                        ?>
					</ul>
				</nav>
			</div>
		</header>

        <?php
        // Clear animal filter variables
            session_start();
            $_SESSION['type'] = "";
            $_SESSION['size'] = "";
            $_SESSION['age'] = "";
            $_SESSION['date'] = "";
            $_SESSION['first_name'] = "";
            $_SESSION['last_name'] = "";
            $_SESSION['a_name'] = "";
            $_SESSION['transaction_type'] = "";
            $_SESSION['transaction_name'] = "";

        // Connect to databse
            include('connection.php');
        
        // Variables
            $profile_id = $_SESSION['active_user_id'];
            $animal_id = $_SESSION['animal_id'];
            $query = mysqli_query($con, "SELECT First_Name FROM profile WHERE PROFILE_ID = '$profile_id'");
            $query2 = mysqli_query($con, "SELECT Last_Name FROM profile WHERE PROFILE_ID = '$profile_id'");
            $query3 = mysqli_query($con, "SELECT Name FROM animal WHERE ANIMAL_ID = '$animal_id'");
            $row = $query->fetch_assoc();
            $row2 = $query2->fetch_assoc();
            $row3 = $query3->fetch_assoc();
            $first_name = $row['First_Name'];
            $last_name = $row2['Last_Name'];
            $animal_name = $row3['Name'];


        // Show animal name as header
            echo '<h1 align = "center">' . $animal_name . '</h1>';
        
        ?>

        <!--Buttons-->
            <div class = "buttons" style = "text-align: center">
            <a href = "adopt.php">
            <button type = "button" class = "button_1">ADOPT</button>
            </a>
            <a href = "inquiry.php">
            <button type = "button" class = "button_1">INQUIRE</button>
            </a>
            <a href = "donate.php">
            <button type = "button" class = "button_1">DONATE</button>
            </a>
            <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
           
            <style>
            .fa 
            {
                font-size: 50px;
                cursor: pointer;
                user-select: none;
            }

            .fa:hover 
            {
                color: darkblue;
            }
            </style>

            <?php
            // Variables
                $result = mysqli_query($con, "SELECT Type, Breed, Age, Size, Color, Likes, Donation_Amount, Adoption_Fee FROM animal WHERE ANIMAL_ID = '$animal_id'");
                $row4 = $result->fetch_assoc();
                $type = $row4['Type'];
                $breed = $row4['Breed'];
                $age = $row4['Age'];
                $size = $row4['Size'];
                $color = $row4['Color'];
                $likes = $row4['Likes'];
                $donation = $row4['Donation_Amount'];
                $adoption_fee = $row4['Adoption_Fee'];
                $donation = number_format($donation, 2);
                $adoption_fee = number_format($adoption_fee, 2);

            // If user has not already liked the animal, display LIKE button
                if(mysqli_num_rows(mysqli_query($con, "SELECT PROFILE_ID FROM likes WHERE (PROFILE_ID = '$profile_id' AND ANIMAL_ID = '$animal_id')")) == 0)
                    echo '<a href = "?clicked" class="fa fa-thumbs-up"></a>';

            // If user has already liked the animal, display DISLIKE button
                else
                    echo '<a href = "?clicked2"><i class="fa fa-thumbs-down"></i></a>';

            // If LIKE button is clicked
                if(isset($_GET['clicked']))
                {
                    $sql = "INSERT INTO likes (PROFILE_ID, ANIMAL_ID, First_Name, Last_Name, Animal_Name, Like_Date) 
                            VALUES ('$profile_id', '$animal_id', '$first_name', '$last_name', '$animal_name', NOW())";
                    
                    $sql2 =  "INSERT INTO transactions (Transaction_Date, Transaction_Type, PROFILE_ID, First_Name, Last_Name, ANIMAL_ID, Animal_Name) 
                              VALUES (NOW(), 'Like', '$profile_id', '$first_name', '$last_name', '$animal_id', '$animal_name')";
                        
                    $sql3 = "UPDATE animal SET Likes = Likes + 1 WHERE ANIMAL_ID = '$animal_id'";
                
                    if(!mysqli_query($con, $sql) || !mysqli_query($con, $sql2) || !mysqli_query($con, $sql3))
                        header('Location: error.php');
                
                    header('Location: animal.php');
                }

            // If DISLIKE button is clicked
                else if(isset($_GET['clicked2']))
                {
                    $like = "Like";

                    $sql = "DELETE FROM likes WHERE (PROFILE_ID = '$profile_id' AND ANIMAL_ID = '$animal_id')";

                    $sql2 = "DELETE FROM transactions WHERE (PROFILE_ID = '$profile_id' AND ANIMAL_ID = '$animal_id' AND Transaction_Type = '$like')";
                        
                    $sql3 = "UPDATE animal SET Likes = Likes - 1 WHERE ANIMAL_ID = '$animal_id'";
                    
                    if(!mysqli_query($con, $sql) || !mysqli_query($con, $sql2) || !mysqli_query($con, $sql3))
                        header('Location: error.php');
                    
                    header('Location: animal.php');
                }

                echo '</div>';
                
            // Type
                echo '<div class = "information">';
                echo '<div>';
                echo '<font>Type: ' . $type . ' </font>';
                echo '</div>';
            // Breed
                echo '<div>';
                echo '<font>Breed: ' . $breed . ' </font>';
                echo '</div>';
            // Age
                echo '<div>';
                echo '<font>Age: ' . $age . ' </font>';
                echo '</div>';
            // Size
                echo '<div>';
                echo '<font>Size: ' . $size . ' </font>';
                echo '</div>';
            // Color
                echo '<div>';
                echo '<font>Color: ' . $color . ' </font>';
                echo '</div>';
            // Likes
                echo '<div>';
                echo '<font>Likes: ' . $likes . ' </font>';
                echo '</div>';
            // Donation Amount
                echo '<div>';
                echo '<font>Donation Amount: $' . $donation . ' </font>';
                echo '</div>';
            // Adoption Fee
                echo '<div>';
                echo '<font>Adoption Fee: $' . $adoption_fee . ' </font>';
                echo '</div>';
                echo '</div>';
            ?>
            
            <br>

        <?php
        // Show animal picture
            $i = 1;
            foreach(glob("pictures/*.*") as $picture)
            {
                if($i == $_SESSION['animal_id'])
                {
                    echo '<img src ="' . $picture . '" width = "300" height = "300">';
                }
                $i++;
            }
            
        ?>

        </div>
            <br>

        <footer>
			<p>DJ's Animal Shelter, Copyright &copy; 2019</p>
		</footer>

	</body>
</html>
