<!DOCTYPE html>
<html>
	<head>
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
		
		<meta charset="utf-8">
		<meta name= "viewport" content="width=device-width">
		<meta name= "descriptions" content="User friendly online animal shelter">
		<meta name= "keywords" content="animal, shelter, animal shelter, dogs, cats, adoption, donation, pets">
		<meta name= "author" content="Donovan Almendariz, Jerry Olds">
		<title>Animal Shelter | Add animal to database</title>
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

	<!--Add animal form-->
		<section id= "Create2">
			<div class="container">
				<div class="dark">
					<form method = "post" action = "">
					
						<h1>Add Animal</h1>

						<div class="form-input">
							<input type="text" name = "name" placeholder="Name"/>	
						</div>

						<div class="form-input">
							<input type="number" name = "age" placeholder="Age"/>	
						</div>

						<div class="form-input">
							<input type="text" name = "type" placeholder="Type"/>	
						</div>

						<div class="form-input">
							<input type="text" name = "breed" placeholder="Breed"/>	
						</div>

						<div class="form-input">
							<input type="text" name = "color" placeholder="Color"/>	
						</div>

						<select name ="size">
							<option value = "Small">Small</option>
							<option value = "Medium">Medium</option>
							<option value = "Large">Large</option>
						</select>

						<textarea name = "description" cols = "25" rows = "5" placeholder = "Give a breif description of the animal."></textarea>
						
						<div>
							<font color = "white">Add Photo of Animal: </font>
						</div>
						
						<div class="form-input">
						
							<input  type="file" name = "picture"/>	
						</div>

						<input type="submit" name="submit" class = "button_1" value = "ADD ANIMAL"/>

					</form>
				</div>
			</div>	
		</section>

		<footer>
			<p>DJ's Animal Shelter, Copyright &copy; 2019</p>
		</footer>

<!--Sending new animal data to database-->
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

	if(isset($_POST['submit']) && !empty($_POST['submit']))
	{
	// Variables
		$name = $_POST['name'];
		$age = $_POST['age'];
		$type = $_POST['type'];
		$breed = $_POST['breed'];
		$color = $_POST['color'];
		$size = $_POST['size'];
		$description = $_POST['description'];
		$picture = $_POST['picture'];
				
	// Connect to database
		include('connection.php');

	// Set adoption fee
		$result = mysqli_query($con, "SELECT Adoption_Fee from animal WHERE Size = '$size'");
		
	// If no animal exists with same size
		if(mysqli_num_rows($result) == 0)
		{
			if($size = 'Small')
				$adoption_fee = 100;
			else if($size = 'Medium')
				$adoption_fee = 200;
			else
				$adoption_fee = 300;
		}

	// Set adoption fee equal to an animal with same size
		else
		{
			$row = $result->fetch_assoc();
			$adoption_fee = $row['Adoption_Fee'];
		}

	// Insert new animal to database
		$sql = "INSERT INTO animal (Description, Age, Name, Type, Breed, Size, Color, Availability, Posted_Date, Likes, Donation_Amount, Adoption_Fee) 
				VALUES  ('$description', '$age', '$name', '$type', '$breed', '$size', '$color', 1, NOW(), 0, 0.00, $adoption_fee)";
					
		if(!mysqli_query($con, $sql))
			header('Location: error.php');

		else
		{
		// TODO: Images must be in "pictures" folder in htdocs, I couldnt get it to work
		//       when images where in different locations. Make it so that images can be
		//       uploaded and renamed in any location

		// Images need to correspond to ANIMAL_ID so that the image and the animal match, so
		// this block renames image to the Posted_Date of the animal, that way the images will be
		// ordered correctly in folder so we list the names of the animals by id with correct image
			if(!empty($picture))
			{
				$folder = realpath("pictures");
				$ext = pathinfo($picture, PATHINFO_EXTENSION);
				$date = mysqli_query($con, "SELECT Posted_Date FROM animal WHERE Name = '$name' AND Description = '$description'");
				$row = mysqli_fetch_assoc($date);
				$picture_name = $row['Posted_Date'];
				$ext = ".$ext";
				if(stripos($folder,"\\"))
				{
					if(file_exists("$folder\\$picture_name$ext"))
					{
						$count = 1;
						while(file_exists("$folder\\$picture_name$count$ext"))
							$count++;
						rename("$folder\\$picture", "$folder\\$picture_name$count$ext");
					}
					else
						rename("$folder\\$picture", "$folder\\$picture_name$ext");
				}
				else
				{
					if(file_exists("$folder/$picture_name$ext"))
					{
						$count = 1;
						while(file_exists("$folder/$picture_name$count$ext"))
							$count++;
						rename("$folder/$picture", "$folder/$picture_name$count$ext");
					}
					else
						rename("$folder/$picture", "$folder/$picture_name$ext");
				}
			}
			
		// Disconnect from database
			mysqli_close($con);
		// Re-direct to home page
			header('Location: admin_home.php');
		}
	}
?>

	</body>
</html>