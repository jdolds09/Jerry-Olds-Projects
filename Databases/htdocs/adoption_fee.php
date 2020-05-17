<!DOCTYPE html>
<html>
    <style>
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
	<head>
		<meta charset="utf-8">
		<meta name= "viewport" content="width=device-width">
		<meta name= "descriptions" content="User friendly online animal shelter">
		<meta name= "keywords" content="animal, shelter, animal shelter, dogs, cats, adoption, donation, pets">
		<meta name= "author" content="Donovan Almendariz, Jerry Olds">
		<title>Animal Shelter | Edit animal</title>
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

		<section id= "Create2">
			<div class="container">
				<div class="dark">
					<form method = "post" action = "">
					
						<h1>CHANGE ADOPTION FEE</h1>

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
                            $_SESSION['inquiry_date'] = "";
	                        $_SESSION['inquiry_first_name'] = "";
                            $_SESSION['inquiry_last_name'] = "";
                            $_SESSION['inquiry_a_name'] = "";

                        // Connect to database
                            include('connection.php');

                        // Animal sizes
                            $size1 = "Small";
                            $size2 = "Medium";
                            $size3 = "Large";

                        // Get adoption fee for small-sized animals
                            $result = mysqli_query($con, "SELECT Adoption_Fee FROM animal WHERE Size = '$size1'");
                            if(mysqli_num_rows($result) == 0)
                                $small_fee = 100;
                            else
                            {
                                $row = $result->fetch_assoc();
                                $small_fee = $row['Adoption_Fee'];
                            }
                        
                        // Get adoption fee for medium-sized animals
                            $result2 = mysqli_query($con, "SELECT Adoption_Fee FROM animal WHERE Size = '$size2'");
                            if(mysqli_num_rows($result2) == 0)
                                $medium_fee = 200;
                            else
                            {
                                $row2 = $result2->fetch_assoc();
                                $medium_fee = $row2['Adoption_Fee'];
                            }
                        
                        // Get adoption fee for large-sized animals
                            $result3 = mysqli_query($con, "SELECT Adoption_Fee FROM animal WHERE Size = '$size3'");
                            if(mysqli_num_rows($result3) == 0)
                                $large_fee = 300;
                            else
                            {
                                $row3 = $result3->fetch_assoc();
                                $large_fee = $row3['Adoption_Fee'];
                            }

                        // Form
                            echo '<div class="form-input">';
                            echo '<font>Small-Sized Animal Adoption Fee</font>';
                            echo '<input type="number" step = ".01" name = "small_fee" value="' . $small_fee . '"/>';
                            echo '</div>';

                            echo '<div class="form-input">';
                            echo '<font>Medium-Sized Animal Adoption Fee</font>';
                            echo '<input type="number" step = ".01" name = "medium_fee" value="' . $medium_fee . '"/>';
                            echo '</div>';

                            echo '<div class="form-input">';
                            echo '<font>Large-Sized Animal Adoption Fee</font>';
                            echo '<input type="number" step = ".01" name = "large_fee" value="' . $large_fee . '"/>';	
                            echo '</div>';
                        
                        ?>

						<input type="submit" name="submit" class = "button_1" value = "UPDATE"/>

					</form>
				</div>
			</div>	
		</section>

		<footer>
			<p>DJ's Animal Shelter, Copyright &copy; 2019</p>
		</footer>

<!--Sending new animal data to database-->
<?php
	if(isset($_POST['submit']) && !empty($_POST['submit']))
	{
	// Variables
		$small_fee = $_POST['small_fee'];
		$medium_fee = $_POST['medium_fee'];
		$large_fee = $_POST['large_fee'];
				
	// Connect to database
		include('connection.php');

    // Set new adoption fees
        $sql = mysqli_query($con, "UPDATE animal SET Adoption_Fee = '$small_fee' WHERE Size = '$size1'");
        $sql2 = mysqli_query($con, "UPDATE animal SET Adoption_Fee = '$medium_fee' WHERE Size = '$size2'");
        $sql3 = mysqli_query($con, "UPDATE animal SET Adoption_Fee = '$large_fee' WHERE Size = '$size3'");

	// Disconnect from database
		mysqli_close($con);
	// Re-direct to home page
		header('Location: admin_home.php');
	}
?>

	</body>
</html>