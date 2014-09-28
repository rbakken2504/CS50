<!DOCTYPE html>

<html>

    <head>

        <link href="/css/bootstrap.min.css" rel="stylesheet"/> 
        <link href="/css/bootstrap-theme.min.css" rel="stylesheet"/>
        <link href="/css/styles.css" rel="stylesheet"/>

        <?php if (isset($title)): ?>
            <title>C$50 Finance: <?= htmlspecialchars($title) ?></title>
        <?php else: ?>
            <title>C$50 Finance</title>
        <?php endif ?>

        <script src="/js/jquery-1.10.2.min.js"></script>
        <script src="/js/bootstrap.min.js"></script>
        <script src="/js/scripts.js"></script>

    </head>

    <body>    
      <nav class="navbar navbar-default" role="navigation">
        <div class="container-fluid">
          <ul class="nav navbar-nav">
            <li><a href="/">Portfolio</a></li>
            <li><a href="buy.php">Buy</a></li>
            <li><a href="sell.php">Sell</a></li>
            <li><a href="history.php">History</a></li>
          </ul>
          <ul class="nav navbar-nav navbar-right">
            <li><a href="password.php">Change Password</a></li>
            <li><a href="logout.php">Logout</a></li>
          </ul>
        </div><!-- /.container-fluid -->
      </nav>
      <div class="container">
        <div id="top">
            <a href="/"><img alt="C$50 Finance" src="/img/logo.gif"/></a>
        </div>
      <div id="middle">            
