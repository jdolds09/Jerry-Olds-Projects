<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<meta name= "viewport" content="width=device-width">
		<meta name= "descriptions" content="User friendly online animal shelter">
		<meta name= "keywords" content="animal, shelter, animal shelter, dogs, cats, adoption, donation, pets">
		<meta name= "author" content="Donovan Almendariz, Jerry Olds">
		<title>Animal Shelter | About</title>
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
					<?php
						session_start();
						include('connection.php');
						$profile_id = $_SESSION['active_user_id'];
					
					// If no one has not signed in, go to index page
						if($profile_id == NULL)
							echo '<li><a href= "index.php">Home</a></li>';
					// If an admin has signed in, go to user admin page
						else if(mysqli_num_rows(mysqli_query($con, "SELECT ADMIN_ID FROM admin WHERE ADMIN_ID = '$profile_id'")) != 0)
							echo '<li><a href= "admin_home.php">Home</a></li>';
					// If a user has signed in, go to user home page 
						else
							echo '<li><a href= "user_home.php">Home</a></li>';

					// About link
						echo '<li class= "current"><a href= "about.php">About</a></li>';
						
					// If no user has signed in, display Sign In link
						if($_SESSION['active_user_id'] == NULL)
							echo '<li><a href= "login.php">Sign In</a></li>';
					// If a user has signed in, display Sign Out link
						else
						{
							echo '<li><a href= "?sign_out" >Sign Out</a></li>';
						// Sign out
							if(isset($_GET['sign_out']))
							{
							// Set active_user to NULL
								$_SESSION['active_user_id'] = NULL;
							// Re-direct to index page
								header('Location: index.php');
							}
						}
					?>
					</ul>
				</nav>
			</div>
		</header>

		<section id= "newsletter">
			<div class = "container">
				<h1>Subscribe To Our Newsletter</h1>
				<form>
					<input type="email" placeholder= "Enter Email...">
					<button type = "submit" class= "button_1">Subscribe</button>
				</form>
			</div>
		</section>

		<section id= "main">
			<div class= "container">
				<article id= "main-col">
					<h1 class="page-title">About Us</h1>
					<p>
						DJ's Animal Shelter is an online, searchable database of animals who need homes. It is also a directory of nearly 11,000 animal shelters and adoption organizations across the U.S., Canada and Mexico. Organizations maintain their own home pages and available-pet databases.
					</p>
					<div class="dark">	
					<p>
						Our mission <br/>
						To use Internet technology and the resources it can generate to:
					</p>
					<p>
						Increase public awareness of the availability of high-quality adoptable pets
						Increase the overall effectiveness of pet adoption programs across North America to the extent that the euthanasia of adoptable pets is eliminated
						Elevate the status of pets to that of family member
						From the comfort of their personal computers, pet lovers can search for a pet that best matches their needs. They can then reference a shelter’s web page and discover what services it offers. DJ's Animal Shelter also includes discussion forums, a pet-care resource directory and a library of free pet-care articles to help keep pets in their homes.

						DJ's Animal Shelter is updated DAILY.
					</div>
					</p>
				</article>

				<aside id="sidebar">
					<div class="dark">
						<h3>What We Do</h3>
						<p>Thank you for your interest in pet adoption! Whether you’re just looking, or you’re ready to adopt, we’re here to provide the necessary information for adopters to help their pets adjust to life in their new home.
						</p>
					</div>
				</aside>
			</div>
		</section>

<?php

	$_SESSION['type'] = "";
	$_SESSION['size'] = "";
	$_SESSION['age'] = "";
	$_SESSION['date'] = "";
	$_SESSION['first_name'] = "";
	$_SESSION['last_name'] = "";
	$_SESSION['a_name'] = "";
	$_SESSION['transaction_type'] = "";
	$_SESSION['transaction_name'] = "";

?>

		<footer>
			<p>DJ's Animal Shelter, Copyright &copy; 2019</p>
		</footer>

	</body>
</html>
