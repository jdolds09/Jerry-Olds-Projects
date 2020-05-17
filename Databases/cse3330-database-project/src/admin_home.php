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
		<title>Animal Shelter | Welcome</title>
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

		<section id= "showcase">
			<div class= "container">
				<h1>Adopt A Pet!</h1>
				<p>Adopting a pet is a big step — but we have a feeling your family is ready to grow. Before starting your search, get tips on choosing the right pet for your lifestyle, preparing your home for a furry family member, and even become a training expert before bringing your pet home.
				</p>
			</div>
		</section>

		<section id= "newsletter">
			<div class = "container">
				<h1>Subscribe To Our Newsletter</h1>
				<form>
					<input type="email" placeholder= "Enter Email...">
					<button type = "submit" class= "button_1">Subscribe</button>
				</form>
			</div>
		</section>

		<section id= "boxes">
			<div class= "container">
				<div class= "box">
					<img src="./img/dog.jpg">
					<h3>DOG</h3>
					<p>A domesticated carnivorous mammal that typically has a long snout, an acute sense of smell, nonretractable claws, and a barking, howling, or whining voice.
					</p>
				</div>

				<div class= "box">
					<img src="./img/cat.jpg">
					<h3>CAT</h3>
					<p>A small domesticated carnivorous mammal with soft fur, a short snout, and retractable claws. It is widely kept as a pet or for catching mice, and many breeds have been developed.
					</p>
				</div>

				<div class= "box">
					<img src="./img/llama.jpg">
					<h3>LLAMA</h3>
					<p>A domesticated pack animal of the camel family found in the Andes, valued for its soft woolly fleece.</p>
				</div>				
			</div>
		</section>

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
		?>

		<footer>
			<p>DJ's Animal Shelter, Copyright &copy; 2019</p>
		</footer>

	</body>
</html>