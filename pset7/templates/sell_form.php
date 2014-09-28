<form action="sell.php" method="post">
  <fieldset>
    <div class="form-group">
    <?php foreach($stocks as $stock): ?>
      <input type="checkbox" class="form-control" name="<?= $stock["symbol"] ?>"/><?= $stock["symbol"] ?><br>
    <?php endforeach ?>
    </div>
    <div class="form-group">
      <button type="submit" class="btn btn-default">Sell</button>
    </div>
  </fieldset>
</form>
