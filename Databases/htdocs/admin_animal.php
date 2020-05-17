<!DOCTYPE html>
<html>
	<head>
        <style>
            a {text-decoration: none;}
            a:visited {text-decoration: none;}
            a:hover {text-decoration: none;}
            a:focus {text-decoration: none;}
            a:hover, .a:active {text-decoration: none;}
            .buttons
            {
                margin-top: -15px;
                text-align: center;
                margin-bottom: 10px;
            }
            .information
            {
                text-align: center;
            }
            img
            {
                display: block;
                margin: 0 auto;
                margin-top: 15px;
            }
            button
            {
                margin-right: 5px;
            }

            /* Navbar container */
			.navbar {
			overflow: hidden;
			font-family: Arial;
			}

			/* Links inside the navbar */
			.navbar a {
			float: left;
			font-size: 16px;
			color: white;
			text-align: center;
			text-decoration: none;
			}

			/* The dropdown container */
			.dropdown {
			float: left;
			overflow: hidden;
			}

			/* Dropdown button */
			.dropdown .dropbtn {
			font-size: 16px; 
			border: none;
			outline: none;
			color: white;
			padding: 14px 16px;
			background-color: inherit;
			font-family: inherit; /* Important for vertical align on mobile phones */
			margin: 0; /* Important for vertical align on mobile phones */
			}

			/* Dropdown content (hidden by default) */
			.dropdown-content {
			display: none;
			position: absolute;
			background-color: #f9f9f9;
			min-width: 160px;
			box-shadow: 0px 8px 16px 0px rgba(0,0,0,0.2);
			z-index: 1;
			}

			/* Links inside the dropdown */
			.dropdown-content a {
			float: none;
			color: black;
			padding: 12px 16px;
			text-decoration: none;
			display: block;
			text-align: left;
			}

			/* Show the dropdown menu on hover */
			.dropdown:hover .dropdown-content {
			display: block;
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
                        
						<div class="navbar">
							<li><a href= "admin_home.php">Home</a></li>
							<li><a href = "admin_animals.php">Animals</a></li>
							<div class="dropdown">
                            <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
								<font class="dropbtn">ADMIN ACTIONS <i class="fa fa-caret-down"></i></font>
								<div class="dropdown-content">
									<a href="add_animal.php">ADD ANIMAL</a>
									<a href="admin_inquiries.php">ANSWER INQUIRIES</a>
									<a href="adoption_fee.php">CHANGE ADOPTION FEES</a>
								</div>
							</div>
							<li><a href = "transactions.php">Transactions</a></li>
							<li><a href= "about.php">About</a></li>
							<li><a href= "?sign_out" >Sign Out</a></li>
						</div> 
						
					<!--Sign Out-->
					</ul>
				</nav>
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
        // Clear filter variables
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
            $query = mysqli_query($con, "SELECT Name, Type, Breed, Age, Size, Color, Likes, Donation_Amount, Adoption_Fee FROM animal WHERE ANIMAL_ID = '$animal_id'");
            $row = $query->fetch_assoc();
            $animal_name = $row['Name'];
            $type = $row['Type'];
            $breed = $row['Breed'];
            $age = $row['Age'];
            $size = $row['Size'];
            $color = $row['Color'];
            $likes = $row['Likes'];
            $donation = $row['Donation_Amount'];
            $adoption_fee = $row['Adoption_Fee'];
            $donation = number_format($donation, 2);
            $adoption_fee = number_format($adoption_fee, 2);

        // Show animal name as header
            echo '<h1 align = "center">' . $animal_name . '</h1>';
        
        // Disconnect from database
            mysqli_close($con);
        ?>

        <!--Buttons-->
            <div class = "buttons" style = "text-align: center">
                <a href = "edit_animal.php">
                    <button type = "button" class = "button_1">EDIT</button>
                </a>

                <a href = "?link=true">
                    <button type = "button" class = "button_1">DELETE</button>
                </a>
            </div>
        
            
        <?php
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
            
    // Show animal picture
            $i = 1;
            foreach(glob("pictures/*.*") as $picture)
            {
                if($i == $_SESSION['animal_id'])
                {
                    echo '<div>';
                    echo '<img src ="' . $picture . '" width = "300" height = "300">';
                    echo '</div>';
                }

                $i++;
            }
        
        // Delete animal
            if(isset($_GET['link']))
            {
            // Connect to database
                include('connection.php');
            
            // Delete animal
                $sql = "DELETE FROM animal WHERE ANIMAL_ID = '$animal_id'";
                $sql2 = "DELETE FROM likes WHERE ANIMAL_ID = '$animal_id'";
                $sql3 = "DELETE FROM transactions WHERE ANIMAL_ID = '$animal_id'";
                $sql4 = "DELETE FROM donations WHERE ANIMAL_ID = '$animal_id'";
                $sql5 = "DELETE FROM inquiries WHERE ANIMAL_ID = '$animal_id'";
            
            // Unsuccessful deletion from database
                if(!mysqli_query($con, $sql) || !mysqli_query($con, $sql2) || !mysqli_query($con, $sql3) || !mysqli_query($con, $sql4) || !mysqli_query($con, $sql5))
                    header('Location: error.php');
            
            // Successful deletion from database
                else
                {
                // Delete picture of animal
                    $i = 1;
                    foreach(glob("pictures/*.*") as $picture)
                    {
                        if($i == $_SESSION['animal_id'])
                        {
                            $k = $i;
                            unlink($picture);
                        }
                    $i++;
                    }
                
                // Reset ANIMAL_IDs
                    $i--;
                    $j = 1;
                    $result = "SELECT ANIMAL_ID from animal";
                    while($j <= $i)
                    {
                        if($j > $k)
                        {
                            $sql2 = "UPDATE animal SET ANIMAL_ID = (ANIMAL_ID - 1) WHERE ANIMAL_ID = '$j'";
                            if(!mysqli_query($con, $sql2))
                                header('Location: error.php');
                        }

                        $j++;
                    }

                // Reset auto increment value
                    mysqli_query($con, "ALTER TABLE animal AUTO_INCREMENT = $i");
                
                // Disconnect from database
                    mysqli_close($con);

                // Redirect to home page
                    header('Location: admin_home.php');
                }
                
            }
            
        ?>

        </div>
            <br>

        <footer>
			<p>DJ's Animal Shelter, Copyright &copy; 2019</p>
		</footer>

	</body>
</html>
