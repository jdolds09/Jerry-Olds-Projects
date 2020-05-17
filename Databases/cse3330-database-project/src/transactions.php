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

		<h1 align = "center">TRANSACTIONS</h1>

        <!--Filters-->
        <?php
            session_start();
		    echo '<div class = "center">';
			    echo '<form method="post" action="">';
            // Date filter
				echo '<font>Date:</font>';
				echo '<input type = "text" name = "date" value = "' . $_SESSION['date'] . '"/>';
			// First name filter
				echo '<font>First Name:</font>';
				echo '<input type = "text" name = "first_name" value = "' . $_SESSION['first_name'] . '"/>';
			// Last name filter
				echo '<font>Last Name:</font>';
                echo '<input type = "text" name = "last_name" value = "' . $_SESSION['last_name'] . '"/>';
            // Animal name filter
                echo '<font>Animal Name:</font>';
                echo '<input type = "text" name = "a_name" value = "' . $_SESSION['a_name'] . '"/>';
            // Transaction type
                echo '<font>Transaction Type:</font>';
                echo '<select name ="transaction_type">';
                    echo '<option value = "' . $_SESSION['transaction_type'] . '">' . $_SESSION['transaction_name'] . '</option>';
                    echo '<option value = ""></option>';
                    echo '<option value = "1">Adoptions, Donations, and Inquiries</option>';
                    echo '<option value = "2">Adoptions, Donations, and Likes</option>';
                    echo '<option value = "3">Donations, Inquiries, and Likes</option>';
                    echo '<option value = "4">Adoptions and Donations</option>';
                    echo '<option value = "5">Adoptions and Inquiries</option>';
                    echo '<option value = "6">Adoptions and Likes</option>';
                    echo '<option value = "7">Donations and Inquiries</option>';
                    echo '<option value = "8">Donations and Likes</option>';
                    echo '<option value = "9">Inquiries and Likes</option>';
                    echo '<option value = "10">Adoptions</option>';
                    echo '<option value = "11">Donations</option>';
                    echo '<option value = "12">Inquiries</option>';
                    echo '<option value = "13">Likes</option>';
                echo '</select>';

			// Submit button
				echo '<input type = "submit" name = "submit" class = button value = "GO"/>';
			echo '</form>';
		echo '</div>';

        // Clear animal filter variables
            $_SESSION['type'] = "";
            $_SESSION['size'] = "";
            $_SESSION['age'] = "";
            $_SESSION['inquiry_date'] = "";
	        $_SESSION['inquiry_first_name'] = "";
            $_SESSION['inquiry_last_name'] = "";
            $_SESSION['inquiry_a_name'] = "";
        
        // Include over 5000 lines of filter code....
            include('transaction_filters.php');
            
        // End of table
            echo '</table>';

        // If filter is used
        if(isset($_POST['submit']) && !empty($_POST['submit']))
        {
            $_SESSION['date'] = $_POST['date'];
            $_SESSION['first_name'] = $_POST['first_name'];
            $_SESSION['last_name'] = $_POST['last_name'];
            $_SESSION['a_name'] = $_POST['a_name'];

        // Store name of transaction filter option
            if(!empty($_POST['transaction_type']))
            {
                if($_POST['transaction_type'] == 1)
                    $_SESSION['transaction_name'] = "Adoptions, Donations, and Inquiries";
                else if($_POST['transaction_type'] == 2)
                    $_SESSION['transaction_name'] = "Adoptions, Donations, and Likes";
                else if($_POST['transaction_type'] == 3)
                    $_SESSION['transaction_name'] = "Donations, Inquiries, and Likes";
                else if($_POST['transaction_type'] == 4)
                    $_SESSION['transaction_name'] = "Adoptions and Donations";
                else if($_POST['transaction_type'] == 5)
                    $_SESSION['transaction_name'] = "Adoptions and Inquiries";
                else if($_POST['transaction_type'] == 6)
                    $_SESSION['transaction_name'] = "Adoptions and Likes";
                else if($_POST['transaction_type'] == 7)
                    $_SESSION['transaction_name'] = "Donations and Inquiries";
                else if($_POST['transaction_type'] == 8)
                    $_SESSION['transaction_name'] = "Donations and Likes"; 
                else if($_POST['transaction_type'] == 9)
                    $_SESSION['transaction_name'] = "Inquiries and Likes";
                else if($_POST['transaction_type'] == 10)
                    $_SESSION['transaction_name'] = "Adoptions";
                else if($_POST['transaction_type'] == 11)
                    $_SESSION['transaction_name'] = "Donations";
                else if($_POST['transaction_type'] == 12)
                    $_SESSION['transaction_name'] = "Inquiries";
                else
                    $_SESSION['transaction_name'] = "Likes";
            }
            else
                $_SESSION['transaction_name'] = "";

            $_SESSION['transaction_type'] = $_POST['transaction_type'];
            header('Location: transactions.php');
        }
        ?>

		<footer>
			<p>DJ's Animal Shelter, Copyright &copy; 2019</p>
		</footer>

	</body>
</html>
