<!DOCTYPE html>
<html>
	<head>
        <style>
            .answer:visited
            {
                color: blue;
            }
            .center
			{
				text-align: center;
				margin-bottom: 10px;
			}
			select
			{
                margin-left: 5px;
				margin-right: 10px;
			}
            input[type = "text"]
            {
                width: 80px;
                margin-right: 10px;
                margin-left: 5px;
                margin-bottom: 15px;
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
		<title>Animal Shelter | Inquiries</title>
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

		<h1 align = "center">INQUIRIES</h1>

        <?php
        // Filters
            session_start();
            echo '<div class = "center">';
                echo '<form method="post" action="">';
                // Date filter
                    echo '<font>Date:</font>';
                    echo '<input type = "text" name = "date" value = "' . $_SESSION['inquiry_date'] . '"/>';
                // First name filter
                    echo '<font>First Name:</font>';
                    echo '<input type = "text" name = "first_name" value = "' . $_SESSION['inquiry_first_name'] . '"/>';
                // Last name filter
                    echo '<font>Last Name:</font>';
                    echo '<input type = "text" name = "last_name" value = "' . $_SESSION['inquiry_last_name'] . '"/>';
                // Animal name filter
                    echo '<font>Animal Name:</font>';
                    echo '<input type = "text" name = "a_name" value = "' . $_SESSION['inquiry_a_name'] . '"/>';
                // Submit button
                    echo '<input type = "submit" name = "submit" class = button value = "GO"/>';
                echo '</form>';
            echo '</div>';
        

        // Clear filter variables
            $_SESSION['type'] = "";
            $_SESSION['size'] = "";
            $_SESSION['age'] = "";
            $_SESSION['date'] = "";
            $_SESSION['first_name'] = "";
            $_SESSION['last_name'] = "";
            $_SESSION['a_name'] = "";
            $_SESSION['transaction_type'] = "";
            $_SESSION['transaction_name'] = "";

        // Connect to database
            include('connection.php');
            
        // If user has made no inquiries
            if(mysqli_num_rows(mysqli_query($con, "SELECT Question, Answer from inquiries")) == 0)
                echo '<h2 align = "center">No Inquiries Made</h2>';

        // Add even more filter code!
            else
                include('admin_inquiries_filters.php');

        // If filters are used
            if(isset($_POST['submit']) && !empty($_POST['submit']))
            {
                $_SESSION['inquiry_date'] = $_POST['date'];
                $_SESSION['inquiry_first_name'] = $_POST['first_name'];
                $_SESSION['inquiry_last_name'] = $_POST['last_name'];
                $_SESSION['inquiry_a_name'] = $_POST['a_name'];

            // Re-direct to admin_inquiries page
                header('Location: admin_inquiries.php');
            }

        // If Answer Inquiry link is clicked
            if(isset($_GET['link']))
            {
                session_start();
                $_SESSION['inquiry_id'] = $_GET['link'];
                mysqli_close($con);
                header('Location: answer_inquiry.php');
            }
            
        ?>

		<footer>
			<p>DJ's Animal Shelter, Copyright &copy; 2019</p>
		</footer>

	</body>
</html>
