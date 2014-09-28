<div>
  <table class="table table-striped">
    <thead>
      <tr>
        <th>Transaction</th>
        <th>Date/Time</th>
        <th>Symbol</th>
        <th>Shares</th>
        <th>Price</th>
      </tr>
    </thead>
    <tbody>
      <?php foreach($rows as $row): ?>
      <tr>
        <td style="text-align: left;"><?= $row["transaction"] ?></td>
        <td style="text-align: left;"><?= $row["time"] ?></td>
        <td style="text-align: left;"><?= $row["symbol"] ?></td>
        <td style="text-align: left;"><?= $row["shares"] ?></td>
        <td style="text-align: left;"><?= "$" . number_format($row["price"], 2) ?></td>
      </tr>
      <?php endforeach ?>
    </tbody>
  </table>
</div>
<div>
  <a href="javascript:history.go(-1);">Back</a>
</div>
